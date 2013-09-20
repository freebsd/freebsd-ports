# Created by: Neil Blakey-Milner <nbm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ao
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://ekyo.nerim.net/software/pyogg/ \
		http://www.sourcefiles.org/Programming/Development/Modules/Python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyao-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrapper for audio device abstraction library (libao)

LICENSE=	GPLv2

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao

USE_PYTHON=		yes
NO_STAGE=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyao

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/aomodule.so

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} config_unix.py \
		--prefix "${LOCALBASE}"

.include <bsd.port.mk>
