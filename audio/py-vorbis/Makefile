# New ports collection makefile for: pyvorbis
# Date created:		23 Sep 2002
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	vorbis
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.andrewchatham.com/pyogg/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyvorbis-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	Object-oriented Python bindings for the vorbis library

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/_ogg.so:${PORTSDIR}/audio/py-ogg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/_ogg.so:${PORTSDIR}/audio/py-ogg
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/ogg/vorbis.so
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py

.include <bsd.port.mk>
