# New ports collection makefile for:	Python bindings for libtunepimp
# Date created:				Fri Mar 31 21:57:56 UTC 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	libtunepimp
DISTVERSION=	0.4.2
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alex@foxybanana.com
COMMENT=	Python bindings for libtunepimp

BUILD_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/ctypes/__init__.py:${PORTSDIR}/devel/py-ctypes
RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/ctypes/__init__.py:${PORTSDIR}/devel/py-ctypes
LIB_DEPENDS=	tunepimp.3:${PORTSDIR}/audio/libtunepimp

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
