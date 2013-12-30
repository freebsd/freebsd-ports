# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	tempest_for_eliza
PORTVERSION=	1.0.5
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.erikyyy.de/tempest/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to send AM radio signals using a PC monitor

USES=		gmake
GNU_CONFIGURE=	yes
USE_SDL=	sdl

SONGS=		forelise jonny fruehling saints oldmacdonald ungarian \
		godfather starwars tempest
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tempest
	${INSTALL_DATA} ${SONGS:S,^,${WRKSRC}/songs/,} ${STAGEDIR}${PREFIX}/share/tempest
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
