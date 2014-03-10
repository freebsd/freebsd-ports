# Created by: alex@FreeBSD.org
# $FreeBSD$

PORTNAME=	emf
PORTVERSION=	2.7.2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/modeling/emf/emf/downloads/drops/,}
MASTER_SITE_SUBDIR=${PORTVERSION}/R201201300943
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
