PORTNAME=	opendx
PORTVERSION=	4.4.4
PORTREVISION=	41
CATEGORIES=	graphics math java
MASTER_SITES=	http://www.sfr-fresh.com/unix/misc/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	IBM's Open Visualization Data Explorer
WWW=		https://en.wikipedia.org/wiki/IBM_OpenDX

LICENSE=	IBM-OVDX-v1
LICENSE_NAME=	IBM PUBLIC LICENSE - Open Visualization Data Explorer VERSION 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtiff.so:graphics/tiff		\
		libcdf.so:science/cdf

USES=		bison compiler:c++17-lang gl gmake libtool localbase:ldflags magick:6 motif sbrk xorg
USE_CXXSTD=	gnu++11
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_XORG=	x11 xt xinerama xext xpm xmu sm ice

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	ARCH=freebsd

MAKE_JOBS_UNSAFE=	yes

NO_MTREE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_SUB=	ARCH=freebsd
.if defined(WITH_HDF) && !defined(WITHOUT_NETCDF)
IGNORE=	HDF and NETCDF are conflicting
.endif

.if defined(WITH_HDF)
LIB_DEPENDS+=	libmfhdf.so:science/hdf
.else
CONFIGURE_ARGS+=	--without-hdf
.endif

.if !defined(WITHOUT_NETCDF)
LIB_DEPENDS+=	libnetcdf.so:science/netcdf
.else
CONFIGURE_ARGS+=	--without-netcdf
.endif

.if defined(WITH_JAVA)
ONLY_FOR_ARCHS=	i386
USES+=		java
BUILD_DEPENDS+=	${JAVALIBDIR}/npcosmop211.jar:graphics/cosmoplayer
RUN_DEPENDS+=	${JAVALIBDIR}/npcosmop211.jar:graphics/cosmoplayer
CONFIGURE_ARGS+=	--with-cosmojar-path=${JAVALIBDIR}/npcosmop211.jar \
			--with-java40jar-path=${JAVALIBDIR}/java40.jar \
			--with-jni-path=${JAVA_HOME}/include:${JAVA_HOME}/include/freebsd
PLIST_SUB+=	JAVA=""
DIR2PRUNE=	dx/java/user dx/java/server/nets
.else
CONFIGURE_ARGS+=	--without-javadx
PLIST_SUB+=	JAVA="@comment "
.endif

PLIST_SUB+=	UNAMEP=${ARCH}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${RM} ${WRKSRC}/include/stamp-h.in
.for dir in doc help html man
	@${FIND} ${WRKSRC}/${dir} -type f | ${XARGS} \
		${REINPLACE_CMD} -e "s;/usr/lpp;${PREFIX};g"
.endfor
	@${REINPLACE_CMD} -e "s;/usr/X11R6;${LOCALBASE};g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|startserver.bat||" \
		${WRKSRC}/src/uipp/java/server/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(ARCH)|@ARCH@|' \
		${WRKSRC}/src/misc/Makefile.*
	@${REINPLACE_CMD} -e 's/void exit (int);/[[noreturn]] void exit (int);/' \
		${WRKSRC}/configure
	for f in `find ${WRKSRC} -name "*.bm"`; do \
		if [ $${f%/*} != "${WRKSRC}/src/uipp/widgets" ]; then \
				${REINPLACE_CMD} -E 's/0x(..)/static_cast<char>(0x\1)/g' $$f; \
				${REINPLACE_CMD} -E 's/static unsigned char/static char/g' $$f; \
		fi; \
	done

post-install:
	@${CP} ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
.if defined(WITH_JAVA)
	${CHMOD} 0775 ${STAGEDIR}${PREFIX}/dx/java/server/nets
	${TOUCH} ${DIR2PRUNE:S|^|${STAGEDIR}${PREFIX}/|:S|$|/.keepme|}
	@${ECHO} "---------------------------------------------------------"	\
		>> ${PKGMESSAGE}
	@${ECHO} "Before starting ${PREFIX}/dx/java/server/bin/startserver"	\
		>> ${PKGMESSAGE}
	@${ECHO} "you must install the port graphics/opendx-samples."		\
		>> ${PKGMESSAGE}
.endif
	@${ECHO} "---------------------------------------------------------"	\
		>> ${PKGMESSAGE}

.include <bsd.port.post.mk>
