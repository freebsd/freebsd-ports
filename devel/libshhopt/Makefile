# New ports collection makefile for:	libshhopt
# Version required:			1.1.6
# Date created:				11 April 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		shhopt-1.1.6
PKGNAME=		libshhopt-1.1.6
CATEGORIES=		devel
MASTER_SITES=		http://home.sol.no/~sverrehu/pub-unix/files/

MAINTAINER=		andy@icc.surw.chel.su

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
