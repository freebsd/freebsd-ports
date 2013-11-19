# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hachoir-parser
PORTVERSION=	1.3.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Parsers of most common file formats

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_core/__init__.py:${PORTSDIR}/devel/hachoir-core
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_core/__init__.py:${PORTSDIR}/devel/hachoir-core

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
