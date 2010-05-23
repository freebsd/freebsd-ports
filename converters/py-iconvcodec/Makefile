# New ports collection makefile for:	py-iconv
# Date created:		23 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	iconvcodec
PORTVERSION=	1.1.2
CATEGORIES=	converters python
MASTER_SITES=	http://download.berlios.de/cjkpython/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Universal unicode codec using iconv(3) for Python

USE_ICONV=	yes
USE_PYTHON=	2.1+
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	--with-libiconv=${LOCALBASE}

.include <bsd.port.mk>
