# Created by: markand
# $FreeBSD$

PORTNAME=	viruskiller
PORTVERSION=	1.03
DISTVERSIONSUFFIX=	-1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	FRUGALWARE/games-extra/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arcade game that relies on quick reflexes

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake gnome sdl
USE_SDL=	mixer image ttf net
MAKEFILE=	makefile
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^DOCS/s|=.*|= doc/README doc/*.*| ; \
		 /^PREFIX/s|=.*|= ${PREFIX}| ; \
		 /^BINDIR/s|=.*|= $$(DESTDIR)$$(PREFIX)/bin/| ; \
		 /^DATADIR/s|=.*|= $$(DESTDIR)$$(PREFIX)/${DATADIR_REL}/| ; \
		 /^DOCDIR/s|=.*|= $$(DESTDIR)$$(PREFIX)/${DOCSDIR_REL}/| ; \
		 /^ICONDIR/s|=.*|= $$(DESTDIR)$$(PREFIX)/share/icons/hicolor/| ; \
		 /^DESKTOPDIR/s|=.*|= $$(DESTDIR)$$(PREFIX)/share/applications/| ; \
		 /^LIBS =/s|$$| -lz| ; \
		 s|install .* 755|$${BSD_INSTALL_PROGRAM}| ; \
		 s|install .* 644|$${BSD_INSTALL_DATA}| ; \
		 /ICONS/s|cp|$${BSD_INSTALL_DATA}|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		's|.png|| ; \
		 s|/usr/games/||' ${WRKSRC}/icons/viruskiller.desktop

.include <bsd.port.mk>
