# New ports collection makefile for:	sex
# Date created:				26 April 2001
# Whom:					Nick Johnson <freebsd@spatula.net>
#
# $FreeBSD$
#

PORTNAME=	sex
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://spatula.net/software/sex/

MAINTAINER=	freebsd@spatula.net
COMMENT=	Spouts silly mad-lib-style porn-like text

MAN6=		sex.6
MANCOMPRESSED=	yes
PLIST_FILES=	bin/sex

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
