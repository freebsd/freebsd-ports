PORTNAME=	mbelib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	comms hamradio

MAINTAINER=	takefu@airport.fm
COMMENT=	P25 Phase 1 and ProVoice vocoder

LICENSE=	ISCL UNKNOWN
LICENSE_COMB=	multi
LICENSE_NAME_UNKNOWN=	Unknwon licene
LICENSE_FILE_ISCL=	${WRKSRC}/COPYRIGHT
LICENSE_FILE_UNKNOWN=	${WRKSRC}/README.md
# Provided for educational purposes only
LICENSE_PERMS_UNKNOWN=	auto-accept

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	szechyjs
USE_LDCONFIG=	yes

CMAKE_ON=	DISABLE_TEST

PLIST_FILES=	include/mbelib.h lib/libmbe.a lib/libmbe.so.1.0 \
		lib/libmbe.so.1 lib/libmbe.so

.include <bsd.port.mk>
