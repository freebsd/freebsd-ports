# ex:ts=8
# Ports collection makefile for:  Mark Moraes malloc library
# Version required: 0.0
# Date created:			  11 January 1995
# Whom:				  jkh
#
# $FreeBSD$
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
	@cd ${PREFIX}/include ; ${LN} -sf malloc.h libmalloc.h
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libmalloc
	${INSTALL_DATA} ${WRKSRC}/malloc.doc ${PREFIX}/share/doc/libmalloc
	${INSTALL_DATA} ${WRKSRC}/NOTE ${PREFIX}/share/doc/libmalloc
.endif

.include <bsd.port.post.mk>
