PORTNAME=	pyside6
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-tools
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PySide6 development tools
WWW=		https://wiki.qt.io/Qt_for_Python

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

LIB_DEPENDS=	libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR} \
		libpyside6.abi${PYTHON_MAJOR_VER}.so:devel/pyside6@${PY_FLAVOR} \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake gl llvm:lib python qt:6 shebangfix tar:xz
USE_GL=		gl
USE_PYTHON=	flavors
USE_QT=		base declarative languageserver tools

SHEBANG_FILES=	pyside_tool.py qtpy2cpp_lib/tests/baseline/basic_test.py

PLIST_SUB=	PYSIDE_BINDIR_REL=${PYSIDE_BINDIR_REL}
WRKSRC=		${WRKDIR}/pyside-setup-everywhere-src-${PYSIDE6_VERSION}/sources/pyside-tools

PYSIDE_RELNAME=		${PORTNAME}
PYSIDE_BINDIR_REL?=	bin/${PYSIDE_RELNAME}

post-install:
# Move scripts into a dedicated directory. They're too generically named, e.g.:
# deploy.py and project.py. Unversioned copies of Qt tools like lrelease and
# rcc are also installed which we probably don't want in PATH by default.
# Install to: ${PREFIX}/bin/pyside6 by default for now until there are
# consumers of this and a more fitting location is deemed necessary.
	@${MV} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/${PYSIDE_RELNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PYSIDE_BINDIR_REL}
	@${MV} ${STAGEDIR}${PREFIX}/${PYSIDE_RELNAME} ${STAGEDIR}${PREFIX}/bin
# These directories contain templates that should not be byte-compiled.
	@${MV} ${STAGEDIR}${PREFIX}/${PYSIDE_BINDIR_REL}/deploy_lib/android/recipes ${WRKDIR}

.for d in deploy_lib project qtpy2cpp_lib
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PREFIX}/${PYSIDE_BINDIR_REL}/${d} \
		${STAGEDIR}${PREFIX}/${PYSIDE_BINDIR_REL}/${d}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PREFIX}/${PYSIDE_BINDIR_REL}/${d} \
		${STAGEDIR}${PREFIX}/${PYSIDE_BINDIR_REL}/${d}
.endfor

	@${MV} ${WRKDIR}/recipes ${STAGEDIR}${PREFIX}/${PYSIDE_BINDIR_REL}/deploy_lib/android

.include <bsd.port.mk>
