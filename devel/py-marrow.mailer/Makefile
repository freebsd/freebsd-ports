PORTNAME=	marrow.mailer
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Python library to ease sending emails
WWW=		https://github.com/marrow/mailer

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marrow.util>=1.2.3:devel/py-marrow.util@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
