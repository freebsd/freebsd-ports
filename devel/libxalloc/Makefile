# New ports collection makefile for:	libxalloc
# Date created:				12 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	libxalloc
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://home.sol.no/~sverrehu/pub-unix/files/
DISTNAME=	xalloc-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org

USE_GMAKE=	yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/libxalloc
	@ ${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/libxalloc
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libxalloc
.endif

.include <bsd.port.mk>
