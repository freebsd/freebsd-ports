# New ports collection makefile for:	xgame
# Date created:        			14 August 2004
# Whom:                			Andreas Berg
#
# $FreeBSD$
#

PORTNAME=	xgame
PORTVERSION=	1.7.1
CATEGORIES=	games
MASTER_SITES=	http://xgame.tlhiv.com/downloads/

MAINTAINER=	aberg@doomnet.de
COMMENT=	A Perl script which enhances gameplay under Linux/Unix

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/xgame

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xgame ${PREFIX}/bin

.include <bsd.port.mk>
