PORTNAME=	libusbsio
PORTVERSION=	2.1.12
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Python wrapper for NXP libusbsio binary library
WWW=		https://pypi.org/project/libusbsio/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libudev.so:devel/libudev-devd \
		libusbsio.so:comms/libusbsio

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

DOS2UNIX_FILES=	libusbsio/*.py

post-extract:
	${MKDIR} ${WRKSRC}/libusbsio/bin/${OPSYS:tl}_${ARCH}
	${LN} -s ${LOCALBASE}/lib/${PORTNAME}.so ${WRKSRC}/libusbsio/bin/${OPSYS:tl}_${ARCH}/libusbsio.so

.include <bsd.port.mk>
