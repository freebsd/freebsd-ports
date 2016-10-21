# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opendx
PORTVERSION=	4.4.4
PORTREVISION=	20
CATEGORIES=	graphics math java
MASTER_SITES=	http://www.sfr-fresh.com/unix/misc/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	IBM's Open Visualization Data Explorer

LICENSE=	IBM-OVDX-v1
LICENSE_NAME=	IBM PUBLIC LICENSE - Open Visualization Data Explorer VERSION 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick	\
		libtiff.so:graphics/tiff		\
		libcdf.so:science/cdf			\
		libXp.so:x11/libXp

USE_XORG=	x11 xt xinerama xext xpm xmu sm ice
USES=		bison motif gmake libtool
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes
CONFIGURE_ENV=	ARCH=freebsd
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
NO_MTREE=	yes
PLIST_SUB=	ARCH=freebsd
PKGMESSAGE=	${WRKDIR}/pkg-message

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
USE_JAVA=	yes
JAVA_VERSION=	1.6+
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
