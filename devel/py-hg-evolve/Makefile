PORTNAME=	hg-evolve
DISTVERSION=	11.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Changeset Evolution with Mercurial
WWW=		https://www.mercurial-scm.org/doc/evolution/

LICENSE=	GPLv2+

RUN_DEPENDS=	hg:devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Do not conflict with devel/mercurial, which also installs hgext3rd/__init__.py
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/hgext3rd/__init__.py

.include <bsd.port.mk>
