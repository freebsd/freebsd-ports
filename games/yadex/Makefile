# New ports collection makefile for:	yadex
# Date created:				17 June 2001
# Whom:					Jordan DeLong <fracture@allusion.net>
#
# $FreeBSD$
#

PORTNAME=	yadex
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.teaser.fr/~amajorel/yadex/

MAINTAINER=	fracture@allusion.net
COMMENT=	A WAD-file editor, for games like Doom and Hexen

USE_XLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN6=		yadex.6 ybsp.6

post-install:
	${CHMOD} 644 ${PREFIX}/etc/yadex/${PORTVERSION}/yadex.cfg

.include <bsd.port.mk>
