# New ports collection makefile for: pyvorbis
# Date created:		23 Sep 2002
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	vorbis
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.andrewchatham.com/pyogg/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyvorbis-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/_oggmodule.so:${PORTSDIR}/audio/py-ogg
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/_oggmodule.so:${PORTSDIR}/audio/py-ogg
LIB_DEPENDS=	vorbis.2:${PORTSDIR}/audio/libvorbis

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py

.include <bsd.port.mk>
