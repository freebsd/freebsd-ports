PORTNAME=	pyside6
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/${PORTNAME}/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-tools
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/${PYSIDE6_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PySide6 development tools
WWW=		https://wiki.qt.io/Qt_for_Python

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

LIB_DEPENDS=	libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR} \
		libpyside6.abi${PYTHON_MAJOR_VER}.so:devel/pyside6@${PY_FLAVOR} \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake gl llvm:lib,min=17,noexport python qt:6 shebangfix tar:xz
USE_GL=		opengl
USE_PYTHON=	flavors
USE_QT=		base declarative languageserver quick3d shadertools tools

SHEBANG_FILES=	pyside_tool.py \
		qtpy2cpp_lib/tests/baseline/basic_test.py

# Starting with PySide 6.10.0, the includes are installed in ${PREFIX}/PySide6,
# so this seems like a good home for the binaries, as well.
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PYSIDE6_RELNAME}

WRKSRC_SUBDIR=	sources/pyside-tools

PLIST_SUB=	PYSIDE6_BINDIR_REL=${PYSIDE6_BINDIR_REL}

PYSIDE6_RELNAME=	PySide6
PYSIDE6_BINDIR_REL=	${PYSIDE6_RELNAME}/bin

post-install:
# These directories contain templates that should not be byte-compiled.
# Temporarily relocate them to avoid errors.
	@${MV} ${STAGEDIR}${PREFIX}/${PYSIDE6_BINDIR_REL}/deploy_lib/android/recipes ${WRKDIR}

.for d in deploy_lib project_lib qtpy2cpp_lib
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PREFIX}/${PYSIDE6_BINDIR_REL}/${d} \
		${STAGEDIR}${PREFIX}/${PYSIDE6_BINDIR_REL}/${d}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PREFIX}/${PYSIDE6_BINDIR_REL}/${d} \
		${STAGEDIR}${PREFIX}/${PYSIDE6_BINDIR_REL}/${d}
.endfor

# Move the aforementioned templates back into STAGEDIR after the byte-compiling
# operation has finished.
	@${MV} ${WRKDIR}/recipes ${STAGEDIR}${PREFIX}/${PYSIDE6_BINDIR_REL}/deploy_lib/android

.include <bsd.port.mk>
