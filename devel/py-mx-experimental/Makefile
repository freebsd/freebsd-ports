# ex:ts=8
# New ports collection makefile for:	py-mx-experimental
# Date created:			Nov 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mx-experimental
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://www.lemburg.com/files/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/include/gmp.h:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/BeeBase/BeeBase.py:${PORTSDIR}/lang/py-mx-base

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|LIBGMPH|${PREFIX}/include|" ${WRKSRC}/mxEXPERIMENTAL.py

.include <bsd.port.mk>
