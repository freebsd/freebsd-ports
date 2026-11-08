PORTNAME=	hg-evolve
DISTVERSION=	12.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hg_evolve-${DISTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Changeset Evolution with Mercurial
WWW=		https://wiki.mercurial-scm.org/EvolveExtension

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		hg:devel/mercurial

USES=		python
USE_PYTHON=	autoplist pep517

# Do not conflict with devel/mercurial, which also installs hgext3rd/__init__.py
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/hgext3rd/__init__.py

NO_ARCH=	yes

.include <bsd.port.mk>
