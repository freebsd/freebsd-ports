# New ports collection makefile for:	eclipse-datatools
# Date created:		Sun  1 Apr 2007 22:18:17 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datatools
DISTVERSION=	1.8.1
CATEGORIES=	java devel databases
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/datatools/downloads/,}
MASTER_SITE_SUBDIR=	${PORTVERSION:R}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	dtp-sdk_${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Data Tools Platform for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/emf:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/share/eclipse/dropins/gef:${PORTSDIR}/java/eclipse-gef

LICENSE=	EPL

WRKSRC=		${WRKDIR}/eclipse
USE_ZIP=	yes

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
