PORTNAME=	git-cola
DISTVERSIONPREFIX=	v
DISTVERSION=	4.14.0
CATEGORIES=	devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Sleek and powerful Git GUI
WWW=		https://git-cola.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		git>=0:devel/git
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}QtPy>=1.7.1:devel/py-QtPy@${PY_FLAVOR}

USES=		desktop-file-utils gmake gnome pyqt:5 python qt:5 \
		shebangfix
USE_GITHUB=	yes
USE_PYQT=	pyqt5
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

MAKE_ARGS=	prefix=${PREFIX} \
		PYTHON=${PYTHON_CMD}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.mk>
