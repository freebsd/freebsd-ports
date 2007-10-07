# New ports collection makefile for:	gflags
# Date created:				19 December 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gflags
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	http://google-gflags.googlecode.com/files/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Commandline flags module for C++

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README gflags.html designstyle.css

post-patch:
	${REINPLACE_CMD} -e 's|^docdir.*|docdir = ${DOCSDIR}|' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^install/s/ install-dist_docDATA//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
