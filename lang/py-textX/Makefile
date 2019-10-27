# $FreeBSD$

PORTNAME=	textX
PORTVERSION=	2.1.0
CATEGORIES=	lang python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Meta-language for DSL implementation inspired by Xtext

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arpeggio>=1.9.0:devel/py-arpeggio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
