# New ports collection makefile for: pyao
# Date created:		23 Sep 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ao
PORTVERSION=	0.8
CATEGORIES=	audio
MASTER_SITES= 	http://www.andrewchatham.com/pyogg/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyao-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py --prefix="${LOCALBASE}"

.include <bsd.port.mk>
