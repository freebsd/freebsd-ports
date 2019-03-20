# $FreeBSD$

PORTNAME=	mbelib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	comms hamradio

MAINTAINER=	takefu@airport.fm
COMMENT=	P25 Phase 1 and ProVoice vocoder

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	szechyjs
USE_LDCONFIG=	yes

CMAKE_ON=	DISABLE_TEST

RESTRICTED=	Provided for educational purposes only

PLIST_FILES=	include/mbelib.h lib/libmbe.a lib/libmbe.so.1.0 \
		lib/libmbe.so.1 lib/libmbe.so

.include <bsd.port.mk>
