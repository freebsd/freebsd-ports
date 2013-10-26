# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	runsnakerun
DISTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
DISTNAME=	${PORTNAME:C/r/R/g:C/s/S/}-${DISTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	GUI Viewer for Python profiling runs

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SquareMap>0:${PORTSDIR}/x11-toolkits/py-SquareMap \
		${PYTHON_PKGNAMEPREFIX}meliae>0:${PORTSDIR}/devel/py-meliae

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:C/r/R/g:C/s/S/}
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
