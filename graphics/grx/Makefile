# Created by: alepulver
# $FreeBSD$

PORTNAME=	grx
PORTVERSION=	2.4.9
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://grx.gnu.de/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2D graphics library

LICENSE=	LGPL20 MIT
LICENSE_COMB=	multi

USES=		gmake
USE_XORG=	x11 xau xcb xdmcp
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

OPTIONS_DEFINE=		BGI BMP JPEG PNG PRINT TIFF ZLIB
OPTIONS_DEFAULT=	BGI BMP PNG PRINT ZLIB
OPTIONS_SUB=		yes

BGI_DESC=		BGI image format support
BGI_CONFIGURE_ENABLE=	bgi
BMP_DESC=		BMP image format support
BMP_CONFIGURE_ENABLE=	bmp
JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png
PRINT_CONFIGURE_ENABLE=	print
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ENABLE=	tiff
ZLIB_CONFIGURE_ENABLE=	zlib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG} && empty(PORT_OPTIONS:MZLIB)
IGNORE=		PNG support requires ZLIB support
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--enable-x86_64
.endif

post-patch:
	@${GREP} -ERl '<(malloc|alloca)\.h>' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -Ee 's|<(malloc\|alloca)\.h>|<stdlib.h>|'
	@${REINPLACE_CMD} -e \
		's|^\(CC[[:blank:]]*=\).*|\1 ${CC}| ; \
		 s|^\(STRIP[[:blank:]]*=\).*|\1 ${TRUE}| ; \
		 s|^\(CCOPT[[:blank:]]*=\).*|\1 ${CPPFLAGS} ${CFLAGS}| ; \
		 s|^\(LDOPT[[:blank:]]*=\).*|\1 ${LDFLAGS}| ; \
		 s|-m64|| ; \
		 s|-m32||' \
		${WRKSRC}/makedefs.grx
	@${REINPLACE_CMD} -e '/_GR_swap32u/s|length|numchars|' \
		${WRKSRC}/src/fonts/fdv_raw.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgrx20X.so
.for i in bin2c fnt2c xmodetest
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
