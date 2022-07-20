PORTNAME=	xpaint
PORTVERSION=	2.9.10.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple paint program

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png \
		libopenjpeg.so:graphics/openjpeg15 \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libjbig.so:graphics/jbigkit \
		libfontconfig.so:x11-fonts/fontconfig \
		libXaw3dxft.so:x11-toolkits/libxaw3dxft
RUN_DEPENDS=	psselect:print/psutils \
		bash:shells/bash

GNU_CONFIGURE=	yes
USES=		ghostscript:run jpeg libtool:build localbase:ldflags \
		pkgconfig shebangfix tar:bzip2 xorg
USE_XORG=	ice sm x11 xext xft xmu xpm xt
SHEBANG_FILES=	share/bin/imgmerge share/bin/xpaint_ocr

CPPFLAGS+=	-I${LOCALBASE}/include/openjpeg-1.5
MAKE_ENV+=	RM="${RM}"

post-patch:
	@${RM} ${WRKSRC}/XPaint.ad
	@${REINPLACE_CMD} -e 's/-ldl //' \
		${WRKSRC}/configure ${WRKSRC}/rw/configure
	@${REINPLACE_CMD} -e '/^LIBTOOL =/s|=.*|= ${LOCALBASE}/bin/libtool|' \
		-e '/^install-exec-am:/s/install-libLTLIBRARIES//' \
		${WRKSRC}/rw/Makefile.in
	@${REINPLACE_CMD} -e '/if (!image)/s/return;/return -1;/' \
		${WRKSRC}/rw/readWriteTGA.c

post-configure:
	${MAKE} -C ${WRKSRC} clean

.include <bsd.port.mk>
