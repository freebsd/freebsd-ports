# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgilib
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://www.infodrom.org/projects/cgilib/download/ \
		http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/pub/libs/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library of procedures for developing CGI programs in C

USES=		uidfix

USE_LDCONFIG=	yes

MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	include/cgi.h lib/libcgi.a lib/libcgi.so lib/libcgi.so.1 \
		man/man3/cgiDebug.3.gz \
		man/man3/cgiEscape.3.gz \
		man/man3/cgiFree.3.gz \
		man/man3/cgiFreeList.3.gz \
		man/man3/cgiGetCookie.3.gz \
		man/man3/cgiGetCookies.3.gz \
		man/man3/cgiGetFile.3.gz \
		man/man3/cgiGetFiles.3.gz \
		man/man3/cgiGetValue.3.gz \
		man/man3/cgiGetVariables.3.gz \
		man/man3/cgiHeader.3.gz \
		man/man3/cgiInit.3.gz \
		man/man3/cgiRedirect.3.gz \
		man/man3/cgiSetHeader.3.gz \
		man/man3/cgiSetType.3.gz


post-install:
	${INSTALL_DATA} ${WRKSRC}/cgi.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/*.3 ${STAGEDIR}${PREFIX}/man/man3

.include <bsd.port.mk>
