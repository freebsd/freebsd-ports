# New ports collection makefile for:	py-event
# Date created:				23 Feb 2007
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	event
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	http://pyevent.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Python bindings for libevent

LIB_DEPENDS=	event-1.3b:${PORTSDIR}/devel/libevent

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/event.so

.include <bsd.port.mk>
