# $FreeBSD$

PORTNAME=	marrow.mailer
PORTVERSION=	4.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Python library to ease sending emails

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marrow.util>=1.2.3:devel/py-marrow.util@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PY_FUTURES}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
