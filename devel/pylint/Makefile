# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pylint
PORTVERSION=	1.6.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=1.4.5:devel/py-astroid \
		${PYTHON_PKGNAMEPREFIX}isort>=4.2.5:devel/py-isort \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0:devel/py-mccabe \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six

USES=		python
USE_PYTHON=	distutils concurrent

OPTIONS_DEFINE=	GUI

GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} == 2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}configparser>=0:devel/py-configparser \
		${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>=0:devel/py-backports.functools_lru_cache
.endif

.include <bsd.port.post.mk>
