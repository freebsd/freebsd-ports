# New ports collection makefile for:	cgilib
# Date created:				8 May 2005
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgilib
PORTVERSION=	0.7
CATEGORIES=	devel www
MASTER_SITES=	http://www.infodrom.org/projects/cgilib/download/ \
		http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/pub/libs/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A library of procedures for developing CGI programs in C

USE_LDCONFIG=	yes

MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	include/cgi.h lib/libcgi.a lib/libcgi.so lib/libcgi.so.1
MAN3=		cgiDebug.3 cgiFree.3 cgiFreeList.3 cgiGetCookie.3 cgiEscape.3 \
		cgiGetFile.3 cgiGetFiles.3 cgiGetCookies.3 cgiGetValue.3 \
		cgiGetVariables.3 cgiHeader.3 cgiInit.3 cgiRedirect.3 \
		cgiSetHeader.3 cgiSetType.3

post-install:
	${INSTALL_DATA} ${WRKSRC}/cgi.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/*.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
