# New ports collection makefile for:	ccache
# Date created:				31/03/2002
# Whom:			Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	ccache
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ccache.samba.org/ftp/ccache/

MAINTAINER=	ahze@ahze.net
COMMENT=	A tool to minimize the compile time of C/C++ programs

GNU_CONFIGURE=	yes
MAN1=		ccache.1
PLIST_FILES=	bin/ccache

PORTDOCS=	index.html \
		ccache-man.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/web/${i} ${DOCSDIR}
.endfor
.endif
	${STRIP_CMD} ${PREFIX}/bin/ccache

.include <bsd.port.mk>
