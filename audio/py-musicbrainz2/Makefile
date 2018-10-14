# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	musicbrainz2
PORTVERSION=	0.7.4
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/python-musicbrainz2/ \
		http://ftp.osuosl.org/pub/musicbrainz/python-musicbrainz2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-musicbrainz2-${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next Generation Python bindings for MusicBrainz

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

DEPRECATED=	Musicbrainz Web Service 1.0 support ended 2018-08-01
EXPIRATION_DATE=	2018-10-28

LIB_DEPENDS=	libdiscid.so:audio/libdiscid

USES=		python:2.7
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	python-musicbrainz2

.include <bsd.port.mk>
