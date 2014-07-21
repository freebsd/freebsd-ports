# Created by: nbm
# $FreeBSD$

PORTNAME=	ogg
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	audio python
MASTER_SITES=	http://ekyo.nerim.net/software/pyogg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyogg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented Python bindings for the ogg library

LICENSE=	LGPL20

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

.include <bsd.port.mk>
