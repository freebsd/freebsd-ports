# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twisted
PORTVERSION=	18.9.0
CATEGORIES=	devel net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}constantly>=15.1:devel/py-constantly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>17.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperlink>=17.1.1:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=16.10.1:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyHamcrest>=1.9.0:textproc/py-pyhamcrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.4.0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Automat>=0.3.0:devel/py-Automat@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}service_identity>0:security/py-service_identity@${PY_FLAVOR}

USES=		python tar:bzip2
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m twisted.trial -e twisted

.include <bsd.port.mk>
