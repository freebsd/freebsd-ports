# New ports collection makefile for:	libshhopt
# Date created:				11 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		libshhopt
PORTVERSION=		1.1.6
CATEGORIES=		devel
MASTER_SITES=		http://home.sol.no/~sverrehu/pub-unix/files/
DISTNAME=		shhopt-${PORTVERSION}

MAINTAINER=		obrien@FreeBSD.org

USE_GMAKE=		yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/libshhopt
	@ ${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/libshhopt
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libshhopt
.endif
	@ ${MKDIR} ${PREFIX}/share/examples/libshhopt
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile ${PREFIX}/share/examples/libshhopt
	@ ${INSTALL_DATA} ${WRKSRC}/example.c ${PREFIX}/share/examples/libshhopt

.include <bsd.port.mk>
