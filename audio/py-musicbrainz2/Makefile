# New ports collection makefile for:	py-musicbrainz2
# Date created:				Fri Mar 31 21:57:56 UTC 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	musicbrainz2
PORTVERSION=	0.7.0
CATEGORIES=	audio python
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/python-musicbrainz2/ \
		http://uk.musicbrainz.org/pub/musicbrainz/python-musicbrainz2/ \
		http://users.musicbrainz.org/~matt/ \
		http://ftp.osuosl.org/pub/musicbrainz/python-musicbrainz2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-musicbrainz2-${DISTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Next Generation Python bindings for MusicBrainz

BUILD_DEPENDS=	${PYCTYPES}
RUN_DEPENDS=	${PYCTYPES}
LIB_DEPENDS=	discid.2:${PORTSDIR}/audio/libdiscid

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-musicbrainz2

.include <bsd.port.pre.mk>

post-extract:
	@${REINPLACE_CMD} -e 's|libdiscid.so.0|libdiscid.so.2|g' \
		${WRKSRC}/src/musicbrainz2/disc.py

.include <bsd.port.post.mk>
