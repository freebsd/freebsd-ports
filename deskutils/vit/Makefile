PORTNAME=	vit
DISTVERSION=	2.3.4
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Visual Interactive Taskwarrior full-screen terminal interface
WWW=		https://github.com/vit-project/vit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tasklib>=2.4.3:devel/py-tasklib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.1.2:devel/py-urwid@${PY_FLAVOR} \
		task:deskutils/taskwarrior

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
