PORTNAME=	wavpack
DISTVERSION=	5.9.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/dbry/WavPack/releases/download/${DISTVERSION}/ \
		http://www.wavpack.com/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio codec for lossless, lossy, and hybrid compression
WWW=		https://www.wavpack.com/ \
		https://github.com/dbry/WavPack/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing cpe iconv pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	ASM
OPTIONS_DEFAULT=ASM

ASM_CMAKE_BOOL=	WAVPACK_ENABLE_ASM

pre-test:
	@${ECHO_CMD} "====>  NOTE: Test may take 8 minutes or longer to complete"

.include <bsd.port.mk>
