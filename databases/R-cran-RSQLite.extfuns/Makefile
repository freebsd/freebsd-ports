# New ports collection makefile for:	R-cran-RSQLite.extfuns
# Date created:		2012-08-21
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	RSQLite.extfuns
PORTVERSION=	0.0.1
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	SQLite extension functions for RSQLite

LICENSE=	AL2

BUILD_DEPENDS=	R-cran-RSQLite>=0.11.1:${PORTSDIR}/databases/R-cran-RSQLite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
