PORTNAME=	fotocx
PORTVERSION=	24.50
CATEGORIES=	graphics
MASTER_SITES=	https://kornelix.net/downloads/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Image editing and collection management program
WWW=		https://kornelix.net/fotocx/fotocx.html

LICENSE=	GPLv3+

LIB_DEPENDS=	libchamplain-gtk-0.12.so:graphics/libchamplain \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		exiftool:graphics/p5-Image-ExifTool \
		ufraw-batch:graphics/ufraw

USES=		desktop-file-utils gmake gnome jpeg pkgconfig
USE_GNOME=	cairo glib20 gdkpixbuf2 gtk30
ALL_TARGET=	${PORTNAME}
CXXFLAGS+=	-Wno-register -Wno-writable-strings

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/Uninstall/d' ${WRKSRC}/f.widgets.cc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
