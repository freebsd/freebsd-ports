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
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		ccache.1
PLIST_FILES=	bin/ccache

PORTDOCS=	index.html \
		ccache-man.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccache ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/web/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
