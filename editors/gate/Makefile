# New ports collection makefile for:   	gate
# Date created:					15 June 2000
# Whom:                        		James Howard
#
# $FreeBSD$
#

PORTNAME=	gate
PORTVERSION=	2.04c
CATEGORIES=	editors
MASTER_SITES=   http://www.wwnet.net/~janc/software/
DISTNAME=	${PORTNAME}

MAINTAINER=	howardjp@wam.umd.edu

RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	gate gate.1

MAN1=		gate.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gate ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gate.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/gate
	${INSTALL_DATA} ${WRKSRC}/gate.help ${PREFIX}/share/gate

.include <bsd.port.mk>
