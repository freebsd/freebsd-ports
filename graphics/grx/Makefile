# Created by: alepulver
# $FreeBSD$

PORTNAME=	grx
PORTVERSION=	2.4.9
CATEGORIES=	graphics
MASTER_SITES=	http://grx.gnu.de/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 2D graphics library

LICENSE=	LGPL20 MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs

OPTIONS_DEFINE=	BGI BMP JPEG PNG PRINT TIFF ZLIB
OPTIONS_DEFAULT=	ZLIB BGI BMP PNG PRINT
BGI_DESC=	Enable BGI support
BMP_DESC=	Enable BMP support

USE_XORG=	x11 xau xcb xdmcp
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-fontpath=${DATADIR}/fonts \
		--with-x11-base=${LOCALBASE}
ALL_TARGET=	libs
INSTALL_TARGET=	install install-bin install-fonts install-info
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

INFO=		grx

NO_STAGE=	yes
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
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
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
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--enable-tiff
.else
CONFIGURE_ARGS+=--disable-tiff
.endif

.if ${PORT_OPTIONS:MZLIB} || !empty(PORT_OPTIONS:MPNG)
CONFIGURE_ARGS+=--enable-zlib
.else
CONFIGURE_ARGS+=--disable-zlib
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--enable-x86_64
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${GREP} -ERl '<(malloc|alloca)\.h>' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -Ee 's|<(malloc\|alloca)\.h>|<stdlib.h>|'
	@${REINPLACE_CMD} -Ee \
		's|-m32|| ; \
		 s|-m64|| ; \
		 s|^(CC[[:blank:]]*=).*|\1 ${CC}| ; \
		 s|^(CCOPT =)|\1 ${CPPFLAGS} ${CFLAGS}| ; \
		 s|^(LDOPT =)|\1 ${LDFLAGS}| ; \
		 s|lib64|lib|' \
		${WRKSRC}/makedefs.grx
	@${REINPLACE_CMD} -e \
		's|gcc|${CC}| ; \
		 s|lib64|lib|' \
		${WRKSRC}/src/makefile.[lx]*

.include <bsd.port.post.mk>
