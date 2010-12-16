# New ports collection makefile for:	eclipse-gef
# Date created:				July 8, 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gef
PORTVERSION=	3.6.1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/tools/gef/downloads/drops/,}
MASTER_SITE_SUBDIR=	${PORTVERSION}/R201009132020
PKGNAMEPREFIX=	eclipse-
DISTNAME=	GEF-ALL-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Graphical Editing Framework for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

WRKSRC=		${WRKDIR}/eclipse
USE_ZIP=	yes

.include "${.CURDIR}/../eclipse/Makefile.plugins"

.include <bsd.port.mk>
