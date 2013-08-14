# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vor
PORTVERSION=	0.5.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://qualdan.com/vor/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Dodge the rocks until you die

USE_SDL=	mixer image sdl
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PORTDOCS=	README

DESKTOP_ENTRIES="Variations on Rockdodger" \
		"Dodge the rocks until you die" \
		"${DATADIR}/icon.png" \
		"vor" \
		"Game;ArcadeGame;" \
		false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
