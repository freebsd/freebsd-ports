# New ports collection makefile for:	scrollz-doc
# Date created:				31 May 2001
# Whom:					Joshua Coombs <kurlon@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	scrollz-doc
PORTVERSION=	1.0
CATEGORIES=	irc
MASTER_SITES=	http://www.gwi.net/~jcoombs/

MAINTAINER=	kurlon@hotmail.com
COMMENT=	The docs for the scrollz irc client

pre-install:
	${MKDIR} ${PREFIX}/share/doc/scrollz
	${INSTALL_MAN} ${WRKSRC}/ScrollZ.doc ${PREFIX}/share/doc/scrollz
	${INSTALL_MAN} ${WRKSRC}/ScrollZ.help ${PREFIX}/share/doc/scrollz

.include <bsd.port.mk>
