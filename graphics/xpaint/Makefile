# Created by: Steven Wallace <swallace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpaint
PORTVERSION=	2.9.10.3
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Simple paint program

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15 \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libXaw3dxft.so:${PORTSDIR}/x11-toolkits/libxaw3dxft
RUN_DEPENDS=	psselect:${PORTSDIR}/print/psutils \
		bash:${PORTSDIR}/shells/bash

USE_XORG=	xft xmu xpm
USE_GHOSTSCRIPT_RUN=yes
GNU_CONFIGURE=	yes
USES=		jpeg libtool:build shebangfix tar:bzip2
SHEBANG_FILES=	share/bin/imgmerge share/bin/xpaint_ocr

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include/freetype2/freetype
LIBS+=		-L${LOCALBASE}/lib
MAKE_ENV+=	RM="${RM} -f"

post-patch:
	@${RM} -f ${WRKSRC}/XPaint.ad
	@${REINPLACE_CMD} -e 's/-ldl //' \
		-e 's|freetype/||g' \
		${WRKSRC}/configure ${WRKSRC}/rw/configure
	@${REINPLACE_CMD} -e '/^LIBTOOL =/s|=.*|= ${LOCALBASE}/bin/libtool|' \
		-e '/^install-exec-am:/s/install-libLTLIBRARIES//' \
		${WRKSRC}/rw/Makefile.in
	@${REINPLACE_CMD} -e '/if (!image)/s/return;/return -1;/' \
		${WRKSRC}/rw/readWriteTGA.c

post-configure:
	${MAKE} -C ${WRKSRC} clean

.include <bsd.port.mk>
