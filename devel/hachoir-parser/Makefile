# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hachoir-parser
PORTVERSION=	1.3.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Parsers of most common file formats

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-08

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_core/__init__.py:devel/hachoir-core
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_core/__init__.py:devel/hachoir-core

USES=		python:2.7
USE_PYTHON=	distutils

.include <bsd.port.mk>
