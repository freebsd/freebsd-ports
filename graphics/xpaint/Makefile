PORTNAME=	xpaint
DISTVERSION=	3.1.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/sf-${PORTNAME}/sf-${PORTNAME}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple paint program
WWW=		https://sf-xpaint.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjbig.so:graphics/jbigkit \
		libnetpbm.so:graphics/netpbm \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libXaw3dxft.so:x11-toolkits/libxaw3dxft
RUN_DEPENDS=	bash:shells/bash \
		psselect:print/psutils

USES=		autoreconf desktop-file-utils gmake jpeg libtool:build \
		localbase:ldflags pkgconfig shebangfix tar:bzip2 xorg
USE_XORG=	ice sm x11 xext xft xmu xpm xt

SHEBANG_FILES=	share/bin/imgmerge share/bin/xpaint_ocr
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

# util/Makefile and vxp2ps/Makefile needs it
BINARY_ALIAS=	make=${GMAKE}

# Do not install libraries
pre-build:
	@${REINPLACE_CMD} -e '/^install-exec-am:/s/install-libLTLIBRARIES//' \
		${WRKSRC}/xpaintrw/Makefile.in

.include <bsd.port.mk>
