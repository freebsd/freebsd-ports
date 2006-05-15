# New ports collection makefile for:	py-freeimagepy
# Date created:		2005-09-01
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	freeimagepy
PORTVERSION=	1.2.4
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FreeImagePy_w_dll_${PORTVERSION}

MAINTAINER=	whitekid@gmail.com
COMMENT=	A FreeImage library python wrapper

LIB_DEPENDS=	freeimage:${PORTSDIR}/graphics/freeimage

WRKSRC=		${WRKDIR}/FreeImagePy
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
