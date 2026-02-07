PORTNAME=	urwidgets
PORTVERSION=	0.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/AnonymouX47/urwidgets/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of widgets for urwid
WWW=		https://urwidgets.readthedocs.io/en/stable/ \
		https://github.com/AnonymouX47/urwidgets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urwid>=2.1<3.0:devel/py-urwid@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
