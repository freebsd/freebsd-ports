# New ports collection makefile for:	dircproxy
# Date created:				11 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	dircproxy
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.securiweb.net/pub/oss/dircproxy/1.0/ \
		ftp://ftp.netsplit.com/pub/dircproxy/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A detachable irc proxy server with many features

GNU_CONFIGURE=	yes

MAN1=		dircproxy.1 dircproxy-crypt.1
SUB_FILES=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
