# $FreeBSD$

PORTNAME=	option_merge
PORTVERSION=	0.9.9.7
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Code to deeply merge multiple python dictionaries

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}delfick_error>=1.6:devel/py-delfick_error@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}noseofyeti>=1.4.9:devel/py-noseofyeti@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	delfick
GH_TAGNAME=	2940589
USE_PYTHON=	autoplist distutils

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m nose --with-noy

.include <bsd.port.mk>
