# New ports collection makefile for:	starlanes
# Date created:				7 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	starlanes
PORTVERSION=	1.2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The classic space-age stock trading game

ALL_TARGET=	# empty
MAN6=		starlanes.6
PLIST_FILES=	bin/starlanes

post-extract:
	@${RM} ${WRKSRC}/starlanes

.include <bsd.port.mk>
