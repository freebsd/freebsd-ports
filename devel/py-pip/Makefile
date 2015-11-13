# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pip
PORTVERSION=	7.0.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for installing and managing Python packages

LICENSE=	MIT

# Tests also need bzr, git, otherwise they fail
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-capturelog>0:${PORTSDIR}/devel/py-pytest-capturelog \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:${PORTSDIR}/devel/py-pytest-timeout \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:${PORTSDIR}/devel/py-pytest-xdist \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=13.0.0:${PORTSDIR}/devel/py-virtualenv \
		${PYTHON_PKGNAMEPREFIX}scripttest>=1.3:${PORTSDIR}/devel/py-scripttest \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}pretend>0:${PORTSDIR}/devel/py-pretend \
		${PYTHON_PKGNAMEPREFIX}freezegun>0:${PORTSDIR}/devel/py-freezegun \
		git>0:${PORTSDIR}/devel/git \
		bzr>0:${PORTSDIR}/devel/bzr

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_MAKE_ENV=		HOME=${WRKDIR}

USES=		python shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	pip/__init__.py

GH_ACCOUNT=	pypa

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -n --all-files --fresh-env
.endif

post-install:
#	${RM} ${STAGEDIR}${PREFIX}/bin/pip2
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
