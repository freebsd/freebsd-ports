# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aklabeth
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://reconstruction.voyd.net/zips/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Remake of Richard Garriott's Ultima prequel

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		sdl
USE_SDL=	sdl

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	AUTHORS README

DESKTOP_ENTRIES="Aklabeth" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;RolePlaying;" \
		""

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
