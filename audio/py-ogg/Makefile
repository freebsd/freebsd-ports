# New ports collection makefile for: pyogg
# Date created:		23 Sep 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ogg
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.andrewchatham.com/pyogg/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyogg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented Python bindings for the ogg library

LIB_DEPENDS=	ogg.5:${PORTSDIR}/audio/libogg

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

.include <bsd.port.mk>
