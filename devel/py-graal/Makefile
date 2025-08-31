PORTNAME=	graal
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generic source code analyzer
WWW=		https://github.com/chaoss/grimoirelab-graal

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

# For the full functionality  we need to install the following tools:
# FOSSology
# ScanCode toolkit
# crossJadoLint
# However for now we will not include them in the dependencies as
# they are optional and not immediately required
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		cloc>0:misc/cloc \
		git>0:devel/git \
		${PYTHON_PKGNAMEPREFIX}bandit>=1.4.0:devel/py-bandit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloc>=0.2.5:devel/py-cloc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}execnet>=1.9.0:sysutils/py-execnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=7.1.1:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=1.0.9:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lizard>=1.16.6:devel/py-lizard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.1:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval>=1.1.1:devel/py-perceval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>=1.2.4:graphics/py-pydot@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=1.8.4:devel/pylint \
		rubygem-github-linguist>0:textproc/rubygem-github-linguist \
		scc>0:devel/scc

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
