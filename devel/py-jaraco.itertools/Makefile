# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jaraco.itertools
PORTVERSION=	1.7.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Tools for working with iterables

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflect>0:devel/py-inflect@${FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
