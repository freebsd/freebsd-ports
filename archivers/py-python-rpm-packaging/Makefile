PORTNAME=	python-rpm-packaging
PORTVERSION=	0.0.20210526
CATEGORIES=	archivers python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Python rpm packaging

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml-include>0:devel/py-pyyaml-include@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management
GH_PROJECT=	python-rpm-packaging
GH_TAGNAME=	a18ca48959c95aefa725317084dd2d3e242e4f71

SHEBANG_FILES=	scripts/brp-python-bytecompile scripts/pythondistdeps.py
NO_BUILD=	yes

PLIST_FILES=	lib/rpm/brp-python-bytecompile \
		lib/rpm/brp-python-hardlink \
		lib/rpm/pythondistdeps.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/rpm/
.for l in brp-python-bytecompile brp-python-hardlink pythondistdeps.py
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/${l} ${STAGEDIR}${PREFIX}/lib/rpm/
.endfor

.include <bsd.port.mk>
