# ex:ts=8
# New ports collection makefile for: Electric Fence
# Date created: 	13 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	electricfence
PORTVERSION=	2.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c
DISTNAME=	ElectricFence-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org

MAN3=		libefence.3

do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/libefence.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
