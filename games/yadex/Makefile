# New ports collection makefile for:	yadex
# Date created:				17 June 2001
# Whom:					Jordan DeLong <fracture@allusion.net>
#
# $FreeBSD$
#

PORTNAME=	yadex
PORTVERSION=	1.5.2
CATEGORIES=	games
MASTER_SITES=	http://www.teaser.fr/~amajorel/yadex/

MAINTAINER=	fracture@allusion.net

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

MAN6=		yadex.6 ybsp.6

post-install:
	${CHMOD} 644 ${PREFIX}/etc/yadex/1.5.2/yadex.cfg

.include <bsd.port.mk>
