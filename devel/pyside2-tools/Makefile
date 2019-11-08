# $FreeBSD$

PORTNAME=	pyside2-tools
DISTVERSION=	5.13.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken2/PySide2-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Pyside2 development tools

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		git>0:devel/git
LIB_DEPENDS=	# more later

USES=		cmake gl python qt:5 shebangfix tar:xz xorg
USE_GL=		gl
USE_PYTHON=	flavors
USE_QT=		3d buildtools_build charts core datavis3d declarative \
		designer gui help location multimedia network opengl \
		printsupport qmake_build script scripttools scxml sensors \
		speech sql svg testlib uitools webchannel webengine \
		websockets widgets x11extras xml xmlpatterns

SHEBANG_FILES=	pyside_tool.py pyside2-uic

CMAKE_ARGS+=	"-DUSE_PYTHON_VERSION=${PYTHON_VER}"

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} >= 3
LIB_DEPENDS+=	libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR} \
		libpyside2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/pyside2@${PY_FLAVOR}
.else
LIB_DEPENDS+=	libshiboken2-${PYTHON_VERSION}.so:devel/shiboken2@${PY_FLAVOR} \
		libpyside2-${PYTHON_VERSION}.so:devel/pyside2@${PY_FLAVOR}
.endif

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION}/sources/pyside2-tools

.include <bsd.port.post.mk>
