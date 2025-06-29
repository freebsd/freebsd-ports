PORTNAME=	awscrt
PORTVERSION=	0.27.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common runtime for AWS Python projects
WWW=		https://github.com/awslabs/aws-crt-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libaws-c-auth.so:security/aws-c-auth \
		libaws-c-cal.so:security/aws-c-cal \
		libaws-c-common.so:devel/aws-c-common \
		libaws-c-compression.so:devel/aws-c-compression \
		libaws-c-event-stream.so:devel/aws-c-event-stream \
		libaws-c-http.so:devel/aws-c-http \
		libaws-c-io.so:devel/aws-c-io \
		libaws-c-mqtt.so:devel/aws-c-mqtt \
		libaws-c-s3.so:devel/aws-c-s3 \
		libaws-c-sdkutils.so:devel/aws-c-sdkutils \
		libaws-checksums.so:devel/aws-checksums \
		libs2n.so:security/s2n-tls

USES=		localbase:ldflags python ssl
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	AWS_CRT_BUILD_FORCE_STATIC_LIBS=0 \
		AWS_CRT_BUILD_USE_SYSTEM_LIBCRYPTO=1 \
		AWS_CRT_BUILD_USE_SYSTEM_LIBS=1 \
		AWS_CRT_BUILD_WARNINGS_ARE_ERRORS=0

# Clean up bundled libraries
post-patch:
	@${RM} -r ${WRKSRC}/crt/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
