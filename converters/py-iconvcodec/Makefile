# New ports collection makefile for:	py-iconv
# Date created:		23 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	iconvcodec
PORTVERSION=	1.1.1
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	koco
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Universal unicode codec using iconv(3) for Python

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	--with-libiconv=${LOCALBASE}

.include <bsd.port.mk>
