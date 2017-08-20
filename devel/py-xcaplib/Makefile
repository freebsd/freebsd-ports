# Created by: Eugene Grosbein <ports@grosbein.net>
# $FreeBSD$

PORTNAME=	xcaplib
PORTVERSION=	1.0.16
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://download.ag-projects.com/XCAP/ \
		http://grosbein.net/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python XCAP client library

LICENSE=	LGPL20 LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.1.2:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}application>=1.1.5:devel/py-application \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
