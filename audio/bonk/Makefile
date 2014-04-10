# Created by: ijliao
# $FreeBSD$

PORTNAME=	bonk
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.logarithmic.net/pfh-files/bonk/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Lossy/lossless audio compressor

DEPRECATED=	Obsolete experimental codec, use audio/flac or audio/wavpack
EXPIRATION_DATE=	2014-07-15

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		PREFIX="${STAGEDIR}${PREFIX}" INSTALL="${INSTALL_PROGRAM}"

PLIST_FILES=	bin/bonk

.include <bsd.port.mk>
