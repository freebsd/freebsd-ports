# $FreeBSD$

PORTNAME=	pyside2
DISTVERSION=	5.13.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken2/PySide2-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python Qt bindings for Qt 5.12+

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		git>0:devel/git
LIB_DEPENDS=	# more later

USES=		cmake gl python qt:5 tar:xz
USE_GL=		gl
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		3d buildtools_build charts core datavis3d declarative \
		designer gamepad gui help location multimedia network opengl \
		printsupport qmake_build remoteobjects script scripttools \
		scxml sensors speech sql svg testlib uitools webchannel \
		webengine websockets widgets x11extras xml xmlpatterns

CMAKE_ARGS+=	"-DUSE_PYTHON_VERSION=${PYTHON_VER}" \
		"-DPYTHON_EXECUTABLE=${PYTHON_CMD}"

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} >= 3
LIB_DEPENDS+=	libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR}
PLIST_SUB+=	PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}
.else
LIB_DEPENDS+=	libshiboken2-${PYTHON_VERSION}.so:devel/shiboken2@${PY_FLAVOR}
PLIST_SUB+=	PYVERSTR=-${PYTHON_VERSION}
.endif

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION}/sources/pyside2

.include <bsd.port.post.mk>
