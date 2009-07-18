# New ports collection makefile for:	grx
# Date created:				1 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	grx
PORTVERSION=	2.4.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://grx.gnu.de/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A 2D graphics library

USE_GCC=	3.4
USE_GMAKE=	yes
USE_XORG=	x11
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-fontpath=${DATADIR}/fonts \
		--with-x11-base=${LOCALBASE}
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
ALL_TARGET=	libs
INSTALL_TARGET=	install install-bin install-fonts install-info

OPTIONS=	BGI "Enable BGI support" on \
		BMP "Enable BMP support" on \
		GPC "Install GNU Pascal Compiler unit" off \
		JPEG "Enable JPEG support" off \
		PNG "Enable PNG support" on \
		PRINT "Enable printing support" on \
		TIFF "Enable TIFF support" off \
		ZLIB "Enable zlib support" on

INFO=		grx

.include <bsd.port.pre.mk>

.if defined(WITH_BGI)
CONFIGURE_ARGS+=--enable-bgi
PLIST_SUB+=	BGI=""
.else
CONFIGURE_ARGS+=--disable-bgi
PLIST_SUB+=	BGI="@comment "
.endif

.if defined(WITH_BMP)
CONFIGURE_ARGS+=--enable-bmp
.else
CONFIGURE_ARGS+=--disable-bmp
.endif

.if defined(WITH_GPC)
RUN_DEPENDS+=	gpc:${PORTSDIR}/lang/gpc
GCC_VER!=	cd ${PORTSDIR}/lang/gpc && ${MAKE} -V GCC_VER
GNU_HOST!=	cd ${PORTSDIR}/lang/gpc && ${MAKE} -V GNU_HOST
PLIST_SUB+=	GPC="" \
		GCC_VER="${GCC_VER}" \
		GNU_HOST="${GNU_HOST}"
.else
PLIST_SUB+=	GPC="@comment "
.endif

.if defined(WITH_JPEG)
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--enable-jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--enable-png
.else
CONFIGURE_ARGS+=--disable-png
.endif

.if defined(WITH_PRINT)
CONFIGURE_ARGS+=--enable-print
PLIST_SUB+=	PRINT=""
.else
CONFIGURE_ARGS+=--disable-print
PLIST_SUB+=	PRINT="@comment "
.endif

.if defined(WITH_TIFF)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--enable-tiff
.else
CONFIGURE_ARGS+=--disable-tiff
.endif

.if defined(WITH_ZLIB) || defined(WITH_PNG)
CONFIGURE_ARGS+=--enable-zlib
.else
CONFIGURE_ARGS+=--disable-zlib
.endif

post-patch:
	@${GREP} -ERl '<(malloc|alloca)\.h>' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -Ee 's|<(malloc\|alloca)\.h>|<stdlib.h>|'
	@${REINPLACE_CMD} -Ee \
		's|^(CC[[:blank:]]*=).*|\1 ${CC}|; \
		 s|^(CCOPT =)|\1 ${CPPFLAGS} ${CFLAGS}|; \
		 s|^(LDOPT =)|\1 ${LDFLAGS}|;' \
		${WRKSRC}/makedefs.grx
	@${REINPLACE_CMD} -e 's/gcc/${CC}/' ${WRKSRC}/src/makefile.[lx]*

post-install:
.if defined(WITH_GPC)
	${INSTALL_DATA} ${WRKSRC}/pascal/grx.pas \
		${PREFIX}/lib/gpc/gcc/${GNU_HOST}/${GCC_VER}/units
.if defined(WITH_BGI)
	${INSTALL_DATA} ${WRKSRC}/pascal/bgi/graph.pas \
		${PREFIX}/lib/gpc/gcc/${GNU_HOST}/${GCC_VER}/units
.endif
.endif

.include <bsd.port.post.mk>
