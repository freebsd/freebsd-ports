# New ports collection makefile for:	py-musicbrainz2
# Date created:				Fri Mar 31 21:57:56 UTC 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	musicbrainz2
PORTVERSION=	0.3.1
CATEGORIES=	audio python
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/python-musicbrainz2/ \
		http://zim.musicbrainz.org/~matt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-musicbrainz2-${DISTVERSION}

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Next Generation Python bindings for MusicBrainz

BUILD_DEPENDS=	${PYCTYPES}
RUN_DEPENDS=	${PYCTYPES}
LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
