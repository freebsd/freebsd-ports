PORTNAME=	volk
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	devel comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Vector-Optimized Library of Kernels

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	liborc-0.4.so:devel/orc

USES=		cmake compiler:c++11-lang python:3.5+

# The tarball does not contain sources for cpu_features
# and CMakeLists.txt does not handle external cpu_features
CMAKE_OFF=	VOLK_CPU_FEATURES

.include <bsd.port.pre.mk>

.if ${ARCH} == armv7
USE_GCC=	yes
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	gnuradio

USE_LDCONFIG=	yes

# Otherwise the shebang doubles in installed version.
# Found by running Q/A tests (stage-qa) with 'DEVELOPER=yes' in /etc/make.conf
post-patch:
	@${REINPLACE_CMD} -e '1d' \
		${WRKSRC}/python/volk_modtool/volk_modtool

# Replace by full version
pre-install:
	@${REINPLACE_CMD} -e 's|#!/usr/local/bin/python3|#!/usr/local/bin/python${PYTHON_VER}|' \
		${WRKDIR}/.build/python/volk_modtool/volk_modtool.exe

.include <bsd.port.post.mk>
