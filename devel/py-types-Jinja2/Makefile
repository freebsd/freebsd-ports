PORTNAME=	types-Jinja2
PORTVERSION=	2.11.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Typing stubs for Jinja2
WWW=		https://pypi.org/project/types-Jinja2/

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}types-MarkupSafe>=0:devel/py-types-MarkupSafe@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
