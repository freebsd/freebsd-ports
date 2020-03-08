# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	runsnakerun
DISTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
DISTNAME=	${PORTNAME:C/r/R/g:C/s/S/}-${DISTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	GUI Viewer for Python profiling runs

LICENSE=	BSD2CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SquareMap>0:x11-toolkits/py-SquareMap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meliae>0:devel/py-meliae@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
