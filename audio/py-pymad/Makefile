# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pymad
PORTVERSION=	0.10
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the MPEG Audio Decoder library

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmad.so:audio/libmad

USES=		python
USE_PYTHON=	autoplist concurrent distutils

do-configure:
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mad.so

.include <bsd.port.mk>
