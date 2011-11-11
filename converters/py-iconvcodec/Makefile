# New ports collection makefile for:	py-iconv
# Date created:		23 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	iconvcodec
PORTVERSION=	1.1.2
CATEGORIES=	converters python
MASTER_SITES=	BERLIOS/cjkpython
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Universal unicode codec using iconv(3) for Python

DEPRECATED=	Included into python itself since version 2.4
EXPIRATION_DATE=	2011-12-11

USE_ICONV=	yes
USE_PYTHON=	2.1+
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	--with-libiconv=${LOCALBASE}

.include <bsd.port.mk>
