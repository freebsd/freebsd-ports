# New ports collection makefile for:	gpasm
# Date created:				4 Aug 2000
# Whom:					Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gpasm
PORTVERSION=	0.9.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sam@inf.enst.fr

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="cc -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/gpasm
	${INSTALL_DATA} ${WRKSRC}/doc/gpasm.ps ${PREFIX}/share/doc/gpasm
	${INSTALL_DATA} ${WRKSRC}/doc/gpasm.pdf ${PREFIX}/share/doc/gpasm
	${INSTALL_DATA} ${WRKSRC}/doc/gpasm.lyx ${PREFIX}/share/doc/gpasm
.endif

.include <bsd.port.mk>
