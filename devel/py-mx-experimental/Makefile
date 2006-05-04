# ex:ts=8
# New ports collection makefile for:	py-mx-experimental
# Date created:			Nov 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mx-experimental
PORTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.egenix.com/files/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sergio@softshark.org
COMMENT=	The eGenix mx Extensions - EXPERIMENTAL Package

BUILD_DEPENDS=	${LOCALBASE}/include/gmp.h:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/BeeBase/BeeBase.py:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|LIBGMPH|${PREFIX}/include|" ${WRKSRC}/mxEXPERIMENTAL.py

.include <bsd.port.mk>
