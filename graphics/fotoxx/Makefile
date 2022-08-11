PORTNAME=	fotoxx
PORTVERSION=	22.18
CATEGORIES=	graphics
MASTER_SITES=	https://kornelix.net/downloads/downloads/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Application to organize and edit image collections

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

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's,= thread,= cartoon::thread,' ${WRKSRC}/f.effects.cc
	@${REINPLACE_CMD} -e \
		'/#include <sys\/prctl\.h>/d' ${WRKSRC}/f.meta.cc
	@${REINPLACE_CMD} -e \
		's,pidof,pgrep -d\\\\ ,' ${WRKSRC}/fotoxx.cc
	@${REINPLACE_CMD} -e \
		'/#include/s,wait\.h,sys/&,' ${WRKSRC}/fotoxx.h
	@${REINPLACE_CMD} -e \
		's|/usr/share/fotoxx|${DATADIR}|' ${WRKSRC}/fotoxx.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fotoxx

.include <bsd.port.mk>
