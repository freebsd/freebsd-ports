PORTNAME=	wgpu
DISTVERSION=	0.32.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebGPU for Python
WWW=		https://wgpu-py.readthedocs.io/ \
		https://github.com/pygfx/wgpu-py

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.15.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rendercanvas>=2.7:graphics/py-rendercanvas@${PY_FLAVOR} \
		${LOCALBASE}/lib/libwgpu_native.so:graphics/wgpu-native

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/wgpu/backends/wgpu_native/_ffi.py

.include <bsd.port.mk>
