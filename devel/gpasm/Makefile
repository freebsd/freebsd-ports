# New ports collection makefile for:	gpasm
# Date created:				4 Aug 2000
# Whom:					Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gpasm
PORTVERSION=	0.8.10
CATEGORIES=	devel
MASTER_SITES=	http://gpasm.sourceforge.net/

MAINTAINER=	sam@inf.enst.fr

GNU_CONFIGURE=	yes
MAKE_ARGS=	DATADIR=${PREFIX}/share/gpasm

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/gpasm
	${INSTALL_DATA} ${WRKSRC}/doc/gpasm.ps ${PREFIX}/share/doc/gpasm
.endif

.include <bsd.port.mk>
