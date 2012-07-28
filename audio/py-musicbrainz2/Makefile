# New ports collection makefile for:	py-musicbrainz2
# Date created:				Fri Mar 31 21:57:56 UTC 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	musicbrainz2
PORTVERSION=	0.7.4
CATEGORIES=	audio python
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/python-musicbrainz2/ \
		http://ftp.osuosl.org/pub/musicbrainz/python-musicbrainz2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-musicbrainz2-${DISTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Next Generation Python bindings for MusicBrainz

LICENSE=	BSD

LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-musicbrainz2

.include <bsd.port.mk>
