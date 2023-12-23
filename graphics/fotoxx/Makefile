PORTNAME=	fotoxx
PORTVERSION=	23.82
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://kornelix.net/downloads/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Image editing and collection management program
WWW=		https://kornelix.net/fotoxx/fotoxx.html

LICENSE=	GPLv3+

LIB_DEPENDS=	libchamplain-gtk-0.12.so:graphics/libchamplain \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		exiftool:graphics/p5-Image-ExifTool \
		ufraw-batch:graphics/ufraw

USES=		desktop-file-utils gmake gnome jpeg pkgconfig
USE_GNOME=	cairo glib20 gdkpixbuf2 gtk30
ALL_TARGET=	fotoxx
CXXFLAGS+=	-Wno-register -Wno-writable-strings

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/#include/s,wait\.h,sys/&,' ${WRKSRC}/fotoxx.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fotoxx

.include <bsd.port.mk>
