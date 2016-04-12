# $FreeBSD$

PORTNAME=	discid
PORTVERSION=	1.1.0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python libdiscid bindings

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libdiscid.so:audio/libdiscid

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
