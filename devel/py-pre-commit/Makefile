PORTNAME=	pre-commit
DISTVERSION=	4.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for managing and maintaining multi-language pre-commit hooks
WWW=		https://pre-commit.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cfgv>=2.0.0:devel/py-cfgv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}identify>=1.0.0:devel/py-identify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nodeenv>=0.11.1:devel/py-nodeenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.10.0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	pre_commit/resources/hook-tmpl

NO_ARCH=	yes

.include <bsd.port.mk>
