# New ports collection makefile for:	cgilib
# Date created:				8 May 2005
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgilib
PORTVERSION=	0.5
CATEGORIES=	devel www
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/pub/libs/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A library of procedures for developing CGI programs in C

INSTALLS_SHLIB=	yes

MAKEFILE=	${FILESDIR}/Makefile.bsd

MAN3=		cgiDebug.3 cgiFree.3 cgiFreeList.3 cgiGetCookie.3 \
		cgiGetCookies.3 cgiGetValue.3 cgiGetVariables.3 cgiHeader.3 \
		cgiInit.3 cgiRedirect.3 cgiSetHeader.3 cgiSetType.3

post-install:
	${INSTALL_DATA} ${WRKSRC}/cgi.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/*.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
