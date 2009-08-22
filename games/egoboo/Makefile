# New ports collection makefile for:	egoboo
# Date created:				Apr 28 2003
# Whom:					Jan Stocker <Jan.Stocker@t-online.de>
#
# $FreeBSD$

PORTNAME=	egoboo
PORTVERSION=	2.7.5
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Linux%20Source%20Distro/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME:S/-/-data-/}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A 3D dungeon crawling adventure in the spirit of NetHack

USE_SDL=	sdl ttf mixer image
USE_GL=		yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/game
MAKEFILE=	Makefile.unix

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/egoboo|${DATADIR}|g; \
		s|cp -a|cp -RPp|; s|/usr/libexec|${PREFIX}/libexec|' \
		${WRKSRC}/egoboo.sh

post-install:
	${MKDIR} ${DATADIR}
	@cd ${WRKDIR}/${DISTNAME:S/-/-data-/} && \
		${COPYTREE_SHARE} . ${DATADIR}

	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
