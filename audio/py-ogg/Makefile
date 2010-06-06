# New ports collection makefile for: pyogg
# Date created:		23 Sep 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ogg
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	audio python
MASTER_SITES=	http://www.andrewchatham.com/pyogg/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyogg-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Object-oriented Python bindings for the ogg library

LIB_DEPENDS=	ogg.7:${PORTSDIR}/audio/libogg

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyogg

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

.include <bsd.port.mk>
