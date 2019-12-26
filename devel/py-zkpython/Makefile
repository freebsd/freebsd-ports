# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zkpython
PORTVERSION=	0.4.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings to Apache Zookeeper

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	APACHE20

LIB_DEPENDS=	libzookeeper_mt.so:devel/libzookeeper

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
