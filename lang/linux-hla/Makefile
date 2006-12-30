# ports collection makefile for: linux-hla
# Date created:         26 December 2006
# Whom:                 Hernan Di Pietro <hernan.di.pietro@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hla
PORTVERSION=	1.86
CATEGORIES=	lang
MASTER_SITES=	http://webster.cs.ucr.edu/AsmTools/HLA/HLAv${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	hla

MAINTAINER=	hernan.di.pietro@gmail.com
COMMENT=	Randall Hyde High-Level Assembly (HLA) port

IA32_BINARY_PORT=	yes
USE_LINUX=	yes
NO_INSTALL_MANPAGES=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hla ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hlaparse ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/hla
	${MKDIR} ${PREFIX}/lib/hla
	${INSTALL_DATA} ${WRKSRC}/hlalib/hlalib.a ${PREFIX}/lib/hla
	${MKDIR} ${PREFIX}/include/hla/os
	${INSTALL_DATA} ${WRKSRC}/include/*.hhf ${PREFIX}/include/hla
	${INSTALL_DATA} ${WRKSRC}/include/*.scc ${PREFIX}/include/hla
	${INSTALL_DATA} ${WRKSRC}/include/os/*.hhf ${PREFIX}/include/hla/os
	${INSTALL_DATA} ${WRKSRC}/include/os/*.scc ${PREFIX}/include/hla/os

post-install:
	${BRANDELF} -t Linux ${PREFIX}/bin/hla
	${BRANDELF} -t Linux ${PREFIX}/bin/hlaparse

	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
