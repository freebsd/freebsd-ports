# New ports collection makefile for:	py-musepack
# Date created:				12 February 2007
# Whom:					Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$

PORTNAME=	musepack
PORTVERSION=	0.4
CATEGORIES=	audio python
MASTER_SITES=	http://www.sacredchao.net/~piman/software/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	Python module that provides the Musepack decoding interface

LIB_DEPENDS=	mpcdec:${PORTSDIR}/audio/libmpcdec

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
MAKE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
