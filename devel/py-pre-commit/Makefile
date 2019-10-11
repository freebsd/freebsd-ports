# $FreeBSD$

PORTNAME=	pre-commit
PORTVERSION=	1.18.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pre_commit-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Framework for managing and maintaining multi-language pre-commit hooks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aspy.yaml>=0:devel/py-aspy.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cfgv>=2.0.0:devel/py-cfgv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}identify>=1.0.0:devel/py-identify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nodeenv>0.11.1:devel/py-nodeenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=1.15.2:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	pre_commit/resources/hook-tmpl

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>=0:devel/py-futures@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
