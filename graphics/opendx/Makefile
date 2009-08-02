# New ports collection makefile for:	opendx
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
# Updates:              Randall Hopper <rhh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx
PORTVERSION=	4.4.4
PORTREVISION=	2
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/
DISTNAME=	dx-${PORTVERSION}

MAINTAINER=	stephen@missouri.edu
COMMENT=	IBM's Open Visualization Data Explorer

LIB_DEPENDS=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick	\
		tiff.4:${PORTSDIR}/graphics/tiff		\
		cdf.0:${PORTSDIR}/science/cdf

USE_XORG=	xinerama xext xpm xmu sm ice 
USE_BISON=	build
USE_GL=		yes
USE_MOTIF=	yes
USE_AUTOTOOLS=	libtool:22
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	ARCH="${OPSYS:L}" \
		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
USE_GMAKE=	yes
NO_MTREE=	yes
PLIST_SUB=	ARCH=${OPSYS:L}
PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(WITH_HDF) && !defined(WITHOUT_NETCDF)
IGNORE=	HDF and NETCDF are conflicting
.endif

.if defined(WITH_HDF)
LIB_DEPENDS+=	mfhdf.3:${PORTSDIR}/science/hdf
.else
CONFIGURE_ARGS+=	--without-hdf
.endif

.if !defined(WITHOUT_NETCDF)
LIB_DEPENDS+=	netcdf.4:${PORTSDIR}/science/netcdf
.else
CONFIGURE_ARGS+=	--without-netcdf
.endif

.if defined(WITH_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.3+
BUILD_DEPENDS+=	${JAVALIBDIR}/npcosmop211.jar:${PORTSDIR}/graphics/cosmoplayer
RUN_DEPENDS+=	${JAVALIBDIR}/npcosmop211.jar:${PORTSDIR}/graphics/cosmoplayer
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

.if defined(WITH_JAVA) && ${ARCH} != "i386"
BROKEN=		does not build
.endif

post-patch:
	@${RM} -f ${WRKSRC}/include/stamp-h.in
.for dir in doc help html man
	@${FIND} ${WRKSRC}/${dir} -type f | ${XARGS} \
		${REINPLACE_CMD} -e "s;/usr/lpp;${PREFIX};g"
.endfor
	@${REINPLACE_CMD} -e "s;-lpthread;${PTHREAD_LIBS};g"	\
		-e "s;/usr/X11R6;${LOCALBASE};g"			\
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|startserver.bat||" \
		${WRKSRC}/src/uipp/java/server/Makefile.in

post-install:
	@${CP} ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
.if defined(WITH_JAVA)
	${CHMOD} 0775 ${PREFIX}/dx/java/server/nets
	${TOUCH} ${DIR2PRUNE:S|^|${PREFIX}/|:S|$|/.keepme|}
	@${ECHO} "---------------------------------------------------------"	\
		>> ${PKGMESSAGE}
	@${ECHO} "Before starting ${PREFIX}/dx/java/server/bin/startserver"	\
		>> ${PKGMESSAGE}
	@${ECHO} "you must install the port graphics/opendx-samples."		\
		>> ${PKGMESSAGE}
.endif
	@${ECHO} "---------------------------------------------------------"	\
		>> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
