# New ports collection makefile for:	Mark Moraes malloc library
# Version required:	1.18
# Date created:		11 January 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.15 1998/12/01 10:13:02 obrien Exp $
#

DISTNAME=	malloc-1.18
PKGNAME=	libmalloc-1.18
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/moraes/

MAINTAINER=	obrien@FreeBSD.org

.include <bsd.port.pre.mk>

MANUAL_PACKAGE_BUILD=	installs malloc.h

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@(cd ${PREFIX}/include ; ln -sf malloc.h libmalloc.h)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libmalloc
	${INSTALL_DATA} ${WRKSRC}/malloc.doc ${PREFIX}/share/doc/libmalloc
	${INSTALL_DATA} ${WRKSRC}/NOTE ${PREFIX}/share/doc/libmalloc
.endif

.include <bsd.port.post.mk>
