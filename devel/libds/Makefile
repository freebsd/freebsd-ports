# New ports collection makefile for:	libds
# Date created:			25 October 2002
# Whom:				Peter Bozarov (kingofgib@users.sourceforge.net)
#
# $FreeBSD$
#

PORTNAME=		libds
PORTVERSION=		1.0
CATEGORIES=		devel
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-2.1
DISTNAME=		libds-2.1

MAINTAINER=		kingofgib@users.sourceforge.net
COMMENT=		ANSI Generic Data Structures Library

USE_LDCONFIG=		yes
ALL_TARGET=		gcc

.include <bsd.port.pre.mk>

MAN3=	libds.3
HTML=	avltree.html heap.html parray.html set.html hashtbl.html \
	index.html queue.html stack.html

# Copy header file and libraries.
do-install:
	${INSTALL_DATA} ${WRKSRC}/ds.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libds.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libds.so ${PREFIX}/lib/libds.so.1

# Make symbolic link to the shared library
# Install man pages.
# Install HTML pages.
post-install:
	${LN} -sf ${PREFIX}/lib/libds.so.1 ${PREFIX}/lib/libds.so
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man3/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/libds
.for i in ${HTML}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/libds/${i}
.endfor
.endif

.include <bsd.port.post.mk>
