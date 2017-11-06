# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mad
PORTVERSION=	0.9
DISTVERSIONPREFIX=	version/
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the MPEG Audio Decoder library

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmad.so:audio/libmad

PORTSCOUT=	ignore:1

USE_PYTHON=	autoplist distutils
USES=		python

GH_ACCOUNT=	jaqx0r
GH_PROJECT=	pymad
USE_GITHUB=	yes

do-configure:
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mad.so

.include <bsd.port.mk>
