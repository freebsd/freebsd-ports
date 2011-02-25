# New ports collection makefile for:	Python bindings for libtunepimp
# Date created:				Fri Mar 31 21:57:56 UTC 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	libtunepimp
DISTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/ \
		ftp://ftp.musicbrainz.org/pub/musicbrainz/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Python bindings for libtunepimp

LIB_DEPENDS=	tunepimp.5:${PORTSDIR}/audio/libtunepimp

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	tunepimp

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
