# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-ride
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Test data editor for Robot Framework

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:${PORTSDIR}/devel/py-robotframework \
		${PYTHON_PKGNAMEPREFIX}robotframework-selenium2library>=1.1.0:${PORTSDIR}/devel/py-robotframework-selenium2library

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PLIST_SUB+=		PYTHON_VER=${PYTHON_VER} PORTNAME=${PORTNAME:S/-/_/} PORTVERSION=${PORTVERSION}
PYDISTUTILS_NOEGGINFO=	yes
USE_WX=		2.8+
WX_COMPS=	python:run

NO_STAGE=	yes
.include <bsd.port.mk>
