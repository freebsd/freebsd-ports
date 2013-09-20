# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	musicbrainz2
PORTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/python-musicbrainz2/ \
		http://ftp.osuosl.org/pub/musicbrainz/python-musicbrainz2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-musicbrainz2-${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next Generation Python bindings for MusicBrainz

LICENSE=	BSD

LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid

USE_PYTHON=	-2.7
NO_STAGE=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-musicbrainz2

.include <bsd.port.mk>
