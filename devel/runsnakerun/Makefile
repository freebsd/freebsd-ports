# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	runsnakerun
DISTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
DISTNAME=	${PORTNAME:C/r/R/g:C/s/S/}-${DISTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	GUI Viewer for Python profiling runs

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SquareMap>0:x11-toolkits/py-SquareMap \
		${PYTHON_PKGNAMEPREFIX}meliae>0:devel/py-meliae

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
