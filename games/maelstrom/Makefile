# New ports collection makefile for:	Maelstrom
# Date created:				13 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	maelstrom
PORTVERSION=	3.0.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.devolution.com/~slouken/projects/Maelstrom/src/
DISTNAME=	Maelstrom-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asteroids-style game for X Window System

USE_X_PREFIX=	yes
USE_SDL=	sdl net
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install_gamedocs
.endif

post-install:
	${CHOWN} root:games ${PREFIX}/bin/Maelstrom
	${CHMOD} 2755 ${PREFIX}/bin/Maelstrom
	${CHMOD} 664 ${PREFIX}/share/Maelstrom/Maelstrom-Scores
	${CHOWN} root:games ${PREFIX}/share/Maelstrom/Maelstrom-Scores

.include <bsd.port.mk>
