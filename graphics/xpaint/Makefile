# Created by: Steven Wallace <swallace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpaint
PORTVERSION=	2.9.9.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Simple paint program

LICENSE=	GPLv3

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libXaw3dxft.so:${PORTSDIR}/x11-toolkits/libxaw3dxft
RUN_DEPENDS=	psselect:${PORTSDIR}/print/psutils \
		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_XORG=	xft xmu xpm
USE_AUTOTOOLS=	libtool
USE_GHOSTSCRIPT_RUN=yes
GNU_CONFIGURE=	yes
USES=		shebangfix
SHEBANG_FILES=	share/bin/imgmerge share/bin/xpaint_ocr

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include/freetype2/freetype
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	RM="${RM} -f"

post-extract:
	@${RM} -f ${WRKSRC}/XPaint.ad

post-patch:
	@${REINPLACE_CMD} -e 's/-ldl //' \
		-e 's|freetype/||g' \
		${WRKSRC}/configure ${WRKSRC}/rw/configure
	@${REINPLACE_CMD} -e '/^LIBTOOL/d' \
		-e '/^install-exec-am:/s/install-libLTLIBRARIES//' \
		${WRKSRC}/rw/Makefile.in
	@${REINPLACE_CMD} -e '/if (!image)/s/return;/return -1;/' \
		${WRKSRC}/rw/readWriteTGA.c

.include <bsd.port.mk>
