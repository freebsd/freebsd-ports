# New ports collection makefile for:	jam
# Date created:		10 July 1998
# Whom:			Jeffrey Hsu <hsu@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jam
PORTVERSION=	2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp1.perforce.com/pub/jam/

MAINTAINER=	hsu@freebsd.org

HTML_DOCS_DIR=	${PREFIX}/share/doc/jam
HTML_DOCS=	Jam.html Jambase.html Jamfile.html Jamlang.html

do-install:
	(cd ${WRKSRC}; \
	 ./jam0 install; \
	 ${MKDIR} ${HTML_DOCS_DIR}; \
	 ${INSTALL_MAN} ${HTML_DOCS} ${HTML_DOCS_DIR})

.include <bsd.port.mk>
