# New ports collection makefile for:   py-generate
# Date created:        26 August 2006
# Whom:                D'Arcy J.M. Cain <darcy@druid.net>
#
# $FreeBSD$
#

PORTNAME=	generate
PORTVERSION=	2.6
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	generate-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@druid.net
COMMENT=	Python module to implement generate

USE_GMAKE=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/generate.so
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	2.2

.include <bsd.port.mk>
