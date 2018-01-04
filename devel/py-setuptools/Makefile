# $FreeBSD$

PORTNAME=	setuptools
PORTVERSION=	38.2.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python packages installer

LICENSE=	PSFL

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist concurrent distutils allflavors

PYDISTUTILS_SETUP=	${PYSETUP}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}distribute-[0-9]*
MAKE_ENV+=		SETUPTOOLS_DISABLE_VERSIONED_EASY_INSTALL_SCRIPT=1

PLIST_FILES=	"@sample %%PYTHON_SITELIBDIR%%/easy-install.pth.dist %%PYTHON_SITELIBDIR%%/easy-install.pth"

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} != ${PYTHON_DEFAULT_VERSION}
SUB_FILES+=	pkg-message
SUB_LIST+=	PYTHON_VER=${PYTHON_VER}
.endif

# These create dependency loops in redports/poudriere, because setuptools
# is currently an explicit BUILD & RUN dependency in Uses/python.mk.
#TEST_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${FLAVOR}
#.if ${PYTHON_REL} < 3300
#TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR}
#.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/easy-install.pth.dist ${STAGEDIR}${PYTHON_SITELIBDIR}/

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
