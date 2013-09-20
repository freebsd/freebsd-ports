# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mad
PORTVERSION=	0.7
CATEGORIES=	audio python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	pymad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymad-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module that provides the MPEG Audio Decoder interface

LICENSE=	LGPL20

LIB_DEPENDS=	mad:${PORTSDIR}/audio/mad

USE_PYTHON=	yes
NO_STAGE=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pymad

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/madmodule.so

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} config_unix.py \
		--prefix ${LOCALBASE}

.include <bsd.port.mk>
