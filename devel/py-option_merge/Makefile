# $FreeBSD$

PORTNAME=	option_merge
PORTVERSION=	0.9.9.7
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Code to deeply merge multiple python dictionaries

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}delfick_error>=1.6:devel/py-delfick_error	\
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}noseofyeti>=1.4.9:devel/py-noseofyeti	\
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock

NO_ARCH=	yes
USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	delfick
GH_TAGNAME=	2940589
USE_PYTHON=	autoplist distutils

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m nose --with-noy

.include <bsd.port.mk>
