# New ports collection makefile for: pyogg
# Date created:		23 Sep 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ogg
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES= 	http://www.andrewchatham.com/pyogg/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyogg-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py

.include <bsd.port.mk>
