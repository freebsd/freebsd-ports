PORTNAME=	wavpack
DISTVERSION=	5.8.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/dbry/WavPack/releases/download/${DISTVERSION}/ \
		http://www.wavpack.com/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio codec for lossless, lossy, and hybrid compression
WWW=		https://www.wavpack.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing cpe iconv pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING WAVPACK_BUILD_DOCS
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	ASM
OPTIONS_DEFAULT=ASM

ASM_CMAKE_BOOL=	WAVPACK_ENABLE_ASM

.include <bsd.port.mk>
