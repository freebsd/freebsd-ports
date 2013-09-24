# Created by: ijliao
# $FreeBSD$

PORTNAME=	bonk
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.logarithmic.net/pfh-files/bonk/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Lossy/lossless audio compressor

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		PREFIX="${STAGEDIR}${PREFIX}" INSTALL="${INSTALL_PROGRAM}"

PLIST_FILES=	bin/bonk

.include <bsd.port.mk>
