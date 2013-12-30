# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kazoo
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Higher Level API to Zookeeper for Python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}gevent>=0.13.8:${PORTSDIR}/devel/py-gevent

USE_PYTHON=	yes
USE_ZIP=	yes
USE_PYDISTUTILS=easy_install
USES=		gmake

NO_STAGE=	yes

.include <bsd.port.mk>
