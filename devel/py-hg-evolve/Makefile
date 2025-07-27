PORTNAME=	hg-evolve
DISTVERSION=	11.1.9
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hg_evolve-${DISTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Changeset Evolution with Mercurial
WWW=		https://www.mercurial-scm.org/doc/evolution/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		hg:devel/mercurial

USES=		python
USE_PYTHON=	autoplist distutils

# Do not conflict with devel/mercurial, which also installs hgext3rd/__init__.py
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/hgext3rd/__init__.py

NO_ARCH=	yes

.include <bsd.port.mk>
