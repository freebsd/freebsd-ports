PORTNAME=	alire
DISTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}-project/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	alr-${DISTVERSION}-full-sources

MAINTAINER=	william.franck@sterna.dev
COMMENT=	Ada LIbrary REpository (ALIRE) management tool, alr
WWW=		https://alire.ada.dev/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	segfault: raised STORAGE_ERROR : s-intman.adb:136 explicit raise

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild
RUN_DEPENDS=	git>0:devel/git
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}e3_testsuite>0:devel/py-e3-testsuite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		git>0:devel/git

USES=		ada:run python shebangfix zip

SHEBANG_FILES=	testsuite/run.py

MAKE_CMD=	gprbuild

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/alr-${PORTVERSION}

PLIST_FILES=	bin/alr \
		etc/bash_completion.d/alr-completion.bash \
		share/applications/alr.desktop \
		share/pixmaps/alr.png
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_DESC=	Install Design and Development documentation

_GPR_ARGS=	-j${MAKE_JOBS_NUMBER} -p -vh -vP2 \
		-XALIRE_BUILD_MODE=${WITH_DEBUG:Urelease:Ddebug} \
		-XALIRE_OS=freebsd
_TESTSUITE_ENV=	ALIRE_TESTSUITE_DISABLE_DOCKER= GH_USERNAME=${PORTNAME}-project

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPR_ARGS} -P alr_env)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/alr \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/alr-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/alr.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/resources/alr.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-test:
	(cd ${WRKSRC}/testsuite && \
		${SETENV} ${_TESTSUITE_ENV} PATH=${PATH}:${_ADAPATH} \
		${PYTHON_CMD} ./run.py)

.include <bsd.port.mk>
