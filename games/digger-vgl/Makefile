# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	digger
PORTVERSION=	20020314
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.digger.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD graphics console (VGL) version of the famous Digger game

ONLY_FOR_ARCHS=	amd64 i386

MAKEFILE=	Makefile.fbsd

OPTIONS_DEFINE=	SOUND DOCS

SOUND_USES=	sdl
SOUND_USE=	SDL=sdl
SOUND_MAKE_ENV= SOUND=yes
SOUND_VARS=	PKGMESSAGE=${PKGDIR}/pkg-message.sound

post-patch:
	@${REINPLACE_CMD} -e 's|Software|Software\\n\\|g' ${WRKSRC}/alpha.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/var/games/digger

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/digger.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
