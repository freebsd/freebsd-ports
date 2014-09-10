# Created by: alex@FreeBSD.org
# $FreeBSD$

PORTNAME=	emf
PORTVERSION=	2.9.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/,}
MASTER_SITE_SUBDIR=modeling/emf/emf/downloads/drops/${PORTVERSION}/R201402031126
PKGNAMEPREFIX=	eclipse-
DISTNAME=	emf-xsd-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Eclipse Modeling Framework

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

USES=		zip
WRKSRC=		${WRKDIR}/eclipse

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
