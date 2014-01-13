# Created by: Eugene Grosbein <ports@grosbein.net>
# $FreeBSD$

PORTNAME=	xcaplib
PORTVERSION=	1.0.16
CATEGORIES=	devel python
MASTER_SITES=	http://download.ag-projects.com/XCAP/ \
		http://grosbein.net/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@grosbein.net
COMMENT=	Python XCAP client library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>=8.1.0:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.1.2:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}application>=1.1.5:${PORTSDIR}/devel/py-application

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=python_${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
