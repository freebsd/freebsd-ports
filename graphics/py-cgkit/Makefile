# ex:ts=8
# Ports collection makefile for:	cgkit
# Date created:			Apr 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cgkit
PORTVERSION=	1.2.0
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Computer Graphics Kit

USE_ZIP=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,iostream\.h,iostream," ${WRKSRC}/src/noisemodule.cpp

.include <bsd.port.mk>
