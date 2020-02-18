# $FreeBSD$

PORTNAME=	Acquisition
PORTVERSION=	4.2.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Allows to obtain attributes from the containment hierarchy

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-03-18

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ExtensionClass>=4.1.1:devel/py-ExtensionClass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Acquisition/_Acquisition.so

.include <bsd.port.mk>
