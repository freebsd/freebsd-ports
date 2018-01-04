# Created by: Paul Mather <paul@gromit.dlib.vt.edu>
# $FreeBSD$

PORTNAME=	pydrive
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyDrive-${PORTVERSION}

MAINTAINER=	paul@gromit.dlib.vt.edu
COMMENT=	Google drive api made easy

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.5.2:www/py-google-api-python-client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
