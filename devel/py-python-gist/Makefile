# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	python-gist
PORTVERSION=	0.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Command line interface for working with github gists

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>0:devel/py-docopt \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>0:security/py-python-gnupg \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses

USE_GITHUB=	yes
GH_ACCOUNT=	jdowner
GH_PROJECT=	gist

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
