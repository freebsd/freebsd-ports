PORTNAME=	volk
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	devel comms hamradio
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	dbe88eb8fe3046745fac7afa17a92e8f47285a70.patch:-p1 \
		dd6d9bf51d98f699c54c783995fcf3cca60c38d8.patch:-p1

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Vector-Optimized Library of Kernels

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	liborc-0.4.so:devel/orc

USES=		cmake:testing compiler:c++17-lang python:3.7+
USE_LDCONFIG=	yes

USE_GITHUB=     nodefault
GH_ACCOUNT=	gnuradio

# The tarball does not contain sources for cpu_features
# and CMakeLists.txt does not handle external cpu_features
CMAKE_OFF=	VOLK_CPU_FEATURES # see https://github.com/gnuradio/volk/issues/556

.include <bsd.port.pre.mk>

.if ${ARCH} == armv7
USE_GCC=	yes
.endif

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
