# New ports collection makefile for:	nqc
# Date created:        11 Aug 1999
# Whom:                kbyanc
#
# $FreeBSD$
#

PORTNAME=	nqc
PORTVERSION=	2.4.r3
CATEGORIES=	lang
MASTER_SITES=	http://www.baumfamily.org/nqc/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kbyanc@FreeBSD.org

USE_GMAKE=	yes
CC=		${CXX}

MAN1=		nqc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nqc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nqc-man-2.1r1-0.man ${PREFIX}/man/man1/nqc.1

.include <bsd.port.mk>
