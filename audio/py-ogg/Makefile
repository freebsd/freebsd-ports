# Created by: nbm
# $FreeBSD$

PORTNAME=	ogg
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	audio python
MASTER_SITES=	http://ekyo.nerim.net/software/pyogg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyogg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented Python bindings for the ogg library

LICENSE=	LGPL20

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		python:2
USE_PYTHON=	distutils autoplist

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ogg/_ogg.so

.include <bsd.port.mk>
