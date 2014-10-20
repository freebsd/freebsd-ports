# Created by: Alexander Botero-Lowry <alexbl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	event
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Python bindings for libevent

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

PROJECTHOST=	pyevent
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
