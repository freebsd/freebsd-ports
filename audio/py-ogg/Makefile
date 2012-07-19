# New ports collection makefile for: pyogg
# Date created:		23 Sep 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	ogg
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	audio python
MASTER_SITES=	http://ekyo.nerim.net/software/pyogg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyogg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented Python bindings for the ogg library

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyogg

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

.include <bsd.port.mk>
