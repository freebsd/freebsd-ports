# New ports collection makefile for:	py-musepack
# Date created:				12 February 2007
# Whom:					Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$

PORTNAME=	musepack
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://www.sacredchao.net/~piman/software/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module that provides the Musepack decoding interface

DEPRECATED=	does not build with audio/musepack
EXPIRATION_DATE=	2010-11-15

LIB_DEPENDS=	mpcdec:${PORTSDIR}/audio/libmpcdec

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pymusepack
PYDISTUTILS_PKGVERSION=	0.3
MAKE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
