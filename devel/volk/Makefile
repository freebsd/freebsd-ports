PORTNAME=	volk
DISTVERSION=	2.5.1
CATEGORIES=	devel comms hamradio
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Vector-Optimized Library of Kernels
WWW=		https://github.com/gnuradio/volk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mako/__init__.py:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	liborc-0.4.so:devel/orc \
		libcpu_features.so:devel/cpu_features

USES=		cmake:testing compiler:c++17-lang python
USE_LDCONFIG=	yes

USE_GITHUB=	nodefault
GH_ACCOUNT=	gnuradio

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
