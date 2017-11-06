# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	epiphany
PORTVERSION=	0.7.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
PKGNAMESUFFIX=	-game
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multiplatform clone of Boulderdash

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		autoreconf localbase
USE_SDL=	sdl mixer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/epiphany-game
PORTDOCS=	AUTHORS README BUGS
PORTDATA=	*

DESKTOP_ENTRIES="Epiphany" \
		"" \
		"" \
		"${PORTNAME}-game" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
