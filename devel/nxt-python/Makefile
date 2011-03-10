# New ports collection makefile for:	nxt-python
# Date created:		9 March 2011
# Whom:			Quentin Stievenart <acieroid@awesom.eu>
#
# $FreeBSD$
#

PORTNAME=	nxt-python
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Python interface for the Lego Mindstorms NXT robot

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}

post-patch:
	# fixes FreeBSD specific bug
	${REINPLACE_CMD} 's|\(self.handle.reset()\)|#\1|' ${WRKSRC}/nxt/usbsock.py

.include <bsd.port.mk>
