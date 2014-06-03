# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	libconcord
PORTVERSION=	1.1
CATEGORIES=	comms
MASTER_SITES=	SF/concordance/concordance/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	concordance-${PORTVERSION}

MAINTAINER=	shurd@sasktel.net
COMMENT=	Python bindings for Logitech Harmony library

LICENSE=	GPLv2

LIB_DEPENDS=	libconcord.so:${PORTSDIR}/comms/libconcord

USE_LDCONFIG=	yes
USES=		tar:bzip2
WRKSRC_SUBDIR=	libconcord/bindings/python
USE_PYTHON=	2.7+
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
