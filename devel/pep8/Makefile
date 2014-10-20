# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	pep8
PORTVERSION=	1.5.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python style guide checker

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: extract
	@(cd ${WRKSRC}; ${PYTHON_CMD} ${PORTNAME}.py \
		--doctest --testsuite=testsuite)

.include <bsd.port.mk>
