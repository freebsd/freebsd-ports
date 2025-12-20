PORTNAME=	sip
PORTVERSION=	${SIP_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_SIP}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/Python-SIP/sip/commit/
PATCHFILES=	79da3321082f17d594b29c22dd94e58276d5d23e.patch:-p1 \
		c8424f0208c09c272977cd75b242b01d45d8ad55.patch:-p1 \
		25010f24cde1f247bb27031543ef5f684fb3c080.patch:-p1 \
		97b0fd965d9eaba621d6a438f0e7436916ffc3e7.patch:-p1 \
		8cb66d205024005cca5851395b82dd59942fa1f8.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator
WWW=		https://github.com/Python-SIP/sip

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_SETUPTOOLS} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python pyqt:sip
USE_PYTHON=	autoplist concurrent pep517
USE_PYQT=	#

NO_ARCH=	yes

.include <bsd.port.mk>
