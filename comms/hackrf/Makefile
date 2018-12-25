# Created by: Tomasz "CeDeROM" CEDRO (http://www.tomek.cedro.info)
# $FreeBSD$

PORTNAME=	hackrf
PORTVERSION=	2017.02.1
CATEGORIES=	comms devel hamradio science security

MAINTAINER=	cederom@tlen.pl
COMMENT=	Low cost open source hardware software radio platform

LICENSE=	GPLv2

USE_GITHUB=	YES
GH_ACCOUNT=	mossmann
GH_TAGNAME=	31a37bd

USES=		cmake
CMAKE_SOURCE_PATH=	${WRKSRC}/host
CMAKE_ARGS=	-DLIBUSB_LIBRARIES=/usr/lib/libusb.so

USE_LDCONFIG=	yes

.include <bsd.port.mk>
