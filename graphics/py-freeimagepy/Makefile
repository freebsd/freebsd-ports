# New ports collection makefile for:	py-freeimagepy
# Date created:		2005-09-01
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	freeimagepy
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	SF
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FreeImagePy_w_dll

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A FreeImage library python wrapper

LIB_DEPENDS=	freeimage.3:${PORTSDIR}/graphics/freeimage

WRKSRC=		${WRKDIR}/FreeImagePy
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	FreeImagePy
PYDISTUTILS_PKGVERSION=	1.4.1

.include <bsd.port.mk>
