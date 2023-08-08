PORTNAME=	pymad
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the MPEG Audio Decoder library
WWW=		https://github.com/jaqx0r/pymad

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmad.so:audio/libmad

USES=		python
USE_PYTHON=	autoplist concurrent distutils

do-configure:
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} config_unix.py --prefix ${LOCALBASE}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
