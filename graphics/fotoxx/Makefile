# Created by: Rod Person <rodperson@rodperson.com>

PORTNAME=	fotoxx
PORTVERSION=	15.05
CATEGORIES=	graphics
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/ \
		http://fossies.org/linux/misc/legacy/ \
		http://www.kornelix.com/uploads/1/3/0/3/13035936/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Application to organize and edit image collections

LICENSE=	GPLv3

LIB_DEPENDS=	libtiff.so:graphics/tiff
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		exiftool:graphics/p5-Image-ExifTool \
		ufraw-batch:graphics/ufraw

USES=		desktop-file-utils gmake gnome pkgconfig
USE_GNOME=	gtk30
ALL_TARGET=	fotoxx

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/fotoxx \
		man/man1/fotoxx.1.gz \
		share/appdata/fotoxx.appdata.xml \
		share/applications/fotoxx.desktop

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-ggdb|| ; \
		 s|-rdynamic|-Wl,-export-dynamic| ; \
		 s|share/man|man| ; \
		 s|-lpthread|-lexecinfo|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|/usr/share/fotoxx|${DATADIR}|' ${WRKSRC}/desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fotoxx

.include <bsd.port.mk>
