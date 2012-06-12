# New ports collection makefile for:	grx
# Date created:				1 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	grx
PORTVERSION=	2.4.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://grx.gnu.de/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 2D graphics library

USE_GMAKE=	yes
USE_XORG=	x11
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-fontpath=${DATADIR}/fonts \
		--with-x11-base=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	libs
INSTALL_TARGET=	install install-bin install-fonts install-info

OPTIONS_DEFINE=	BGI BMP JPEG PNG PRINT TIFF ZLIB
OPTIONS_DEFAULT=	ZLIB BGI BMP PNG PRINT
BGI_DESC=	Enable BGI support
BMP_DESC=	Enable BMP support

INFO=		grx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBGI}
CONFIGURE_ARGS+=--enable-bgi
PLIST_SUB+=	BGI=""
.else
CONFIGURE_ARGS+=--disable-bgi
PLIST_SUB+=	BGI="@comment "
.endif

.if ${PORT_OPTIONS:MBMP}
CONFIGURE_ARGS+=--enable-bmp
.else
CONFIGURE_ARGS+=--disable-bmp
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--enable-jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--enable-png
.else
CONFIGURE_ARGS+=--disable-png
.endif

.if ${PORT_OPTIONS:MPRINT}
CONFIGURE_ARGS+=--enable-print
PLIST_SUB+=	PRINT=""
.else
CONFIGURE_ARGS+=--disable-print
PLIST_SUB+=	PRINT="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--enable-tiff
.else
CONFIGURE_ARGS+=--disable-tiff
.endif

.if ${PORT_OPTIONS:MZLIB} || !empty(PORT_OPTIONS:MPNG)
CONFIGURE_ARGS+=--enable-zlib
.else
CONFIGURE_ARGS+=--disable-zlib
.endif

.if ${ARCH} == amd64
CONFIGURE_ARGS+=--enable-x86_64
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${GREP} -ERl '<(malloc|alloca)\.h>' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -Ee 's|<(malloc\|alloca)\.h>|<stdlib.h>|'
	@${REINPLACE_CMD} -Ee \
		's|-m32||; s|-m64||; \
		 s|^(CC[[:blank:]]*=).*|\1 ${CC}|; \
		 s|^(CCOPT =)|\1 ${CPPFLAGS} ${CFLAGS}|; \
		 s|^(LDOPT =)|\1 ${LDFLAGS}|;' \
		-e 's|lib64|lib|' \
		${WRKSRC}/makedefs.grx
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' -e 's|lib64|lib|' \
		 ${WRKSRC}/src/makefile.[lx]*

.include <bsd.port.mk>
