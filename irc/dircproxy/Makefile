# New ports collection makefile for:	dircproxy
# Date created:				11 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       	dircproxy
PORTVERSION=		1.0.3
CATEGORIES=     	irc
MASTER_SITES=		ftp://ftp.netsplit.com/pub/dircproxy/stable/

MAINTAINER=		lester@mazpe.net

GNU_CONFIGURE=		yes

MAN1=			dircproxy.1 dircproxy-crypt.1

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
