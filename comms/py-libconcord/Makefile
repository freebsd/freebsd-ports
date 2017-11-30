# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libconcord
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/concordance/concordance/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	concordance-${PORTVERSION}

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Python bindings for Logitech Harmony library

LICENSE=	GPLv2

LIB_DEPENDS=	libconcord.so:comms/libconcord

USE_LDCONFIG=	yes
USES=		python:2.7 tar:bzip2
WRKSRC_SUBDIR=	libconcord/bindings/python
USE_PYTHON=	distutils

.include <bsd.port.mk>
