# $FreeBSD$

PORTNAME=	setuptools
PORTVERSION=	44.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	python@FreeBSD.org
COMMENT=	Python packages installer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	allflavors autoplist concurrent distutils

PYDISTUTILS_SETUP=	${PYSETUP}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}distribute-[0-9]*
MAKE_ENV+=		SETUPTOOLS_DISABLE_VERSIONED_EASY_INSTALL_SCRIPT=1

PLIST_FILES=	"@sample %%PYTHON_SITELIBDIR%%/easy-install.pth.dist %%PYTHON_SITELIBDIR%%/easy-install.pth"

.include <bsd.port.pre.mk>

.if ${FLAVOR} != ${FLAVORS:[1]}
SUB_FILES+=	pkg-message
SUB_LIST+=	PYTHON_VER=${PYTHON_VER}
.endif

# These create dependency loops in redports/poudriere, because setuptools
# is currently an explicit BUILD & RUN dependency in Uses/python.mk.
#TEST_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}
#.if ${PYTHON_REL} < 3300
#TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}
#.endif
# pkg install -y py36-pytest py36-mock py36-pytest-fixture-config py36-pytest-virtualenv py36-paver

post-install:
	${INSTALL_DATA} ${FILESDIR}/easy-install.pth.dist ${STAGEDIR}${PYTHON_SITELIBDIR}/

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
