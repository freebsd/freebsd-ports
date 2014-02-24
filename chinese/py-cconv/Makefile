# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cconv
PORTVERSION=	0.5.0
CATEGORIES=	chinese converters python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for chinese/cconv

LICENSE=	GPLv2

LIB_DEPENDS=	libcconv.so:${PORTSDIR}/chinese/cconv

CFLAGS+=	-I${LOCALBASE}/include
PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	yes

.include <bsd.port.mk>
