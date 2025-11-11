PORTNAME=	aiortc
DISTVERSION=	1.14.0
PORTREVISION=	1
CATEGORIES=	devel multimedia python www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WebRTC and ORTC in Python
WWW=		https://github.com/aiortc/aiortc/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}aioice>=0.10.1:devel/py-aioice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}av>=14.0.0:multimedia/py-av@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.1:devel/py-google-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyee>=13.0.0:devel/py-pyee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylibsrtp>=0.10.0:devel/py-pylibsrtp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=25.0.0:security/py-pyopenssl@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent cryptography pep517

post-patch:
	@${REINPLACE_CMD} -e 's|^license = "BSD-3-Clause"|license = { text = "BSD-3-Clause" }|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
