# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	fotoxx
PORTVERSION=	15.05
CATEGORIES=	graphics
MASTER_SITES=	GENTOO/distfiles \
		http://fossies.org/linux/misc/legacy/ \
		http://www.kornelix.com/uploads/1/3/0/3/13035936/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application to organize and edit image collections

LICENSE=	GPLv3

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		dcraw:graphics/dcraw \
		exiftool:graphics/p5-Image-ExifTool \
		ufraw-batch:graphics/ufraw

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		desktop-file-utils execinfo gmake pkgconfig
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
