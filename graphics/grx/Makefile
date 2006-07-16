# New ports collection makefile for:	grx
# Date created:				1 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	grx
PORTVERSION=	2.4.6
CATEGORIES=	graphics
MASTER_SITES=	http://grx.gnu.de/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A 2D graphics library

BROKEN=		fails to compile

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontpath=${DATADIR}/fonts
CONFIGURE_TARGET=

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
.else
CONFIGURE_ARGS+=--disable-bgi
.endif

.if defined(WITH_BMP)
CONFIGURE_ARGS+=--enable-bmp
.else
CONFIGURE_ARGS+=--disable-bmp
.endif

.if defined(WITH_GPC)
RUN_DEPENDS+=	gpc:${PORTSDIR}/lang/gpc
PLIST_SUB+=	GPC=""
.else
PLIST_SUB+=	GPC=""
.endif

.if defined(WITH_JPEG)
LIB_DEPENDS+=	jpeg.9${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--enable-jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.5${PORTSDIR}/graphics/png
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
LIB_DEPENDS+=	tiff.4${PORTSDIR}/graphics/tiff
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
		 s|^(LDOPT =)|\1 ${LDFLAGS}|' \
		${WRKSRC}/makedefs.grx
	@${REINPLACE_CMD} -e 's/gcc/${CC}/' ${WRKSRC}/src/makefile.[lx]*

post-install:
.if defined(WITH_GPC)
	${INSTALL_DATA} ${WRKSRC}/pascal/grx.pas ${PREFIX}/lib/gpc/units
.endif
.if defined(WITH_GPC) && defined(WITH_BGI)
	${INSTALL_DATA} ${WRKSRC}/pascal/bgi/graph.pas ${PREFIX}/lib/gpc/units
.endif

.include <bsd.port.post.mk>
