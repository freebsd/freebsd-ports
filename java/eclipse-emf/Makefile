# New ports collection makefile for:	eclipse-emf
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	emf
PORTVERSION=	2.6.1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/modeling/emf/emf/downloads/drops/,}
MASTER_SITE_SUBDIR=${PORTVERSION:R}.x/R201009141218
PKGNAMEPREFIX=	eclipse-
DISTNAME=	emf-xsd-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Eclipse Modeling Framework

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

WRKSRC=		${WRKDIR}/eclipse
USE_ZIP=	yes

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
