PORTNAME=	wavpack
DISTVERSION=	5.5.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/dbry/WavPack/releases/download/${DISTVERSION}/ \
		http://www.wavpack.com/

PATCH_SITES=	https://github.com/dbry/WavPack/commit/
PATCHFILES=	081a14557ada1f76f8807e00fccc5d71b9c96313.patch:-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio codec for lossless, lossy, and hybrid compression

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing cpe iconv pathfix pkgconfig ssl tar:xz
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING WAVPACK_BUILD_DOCS
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	ASM
OPTIONS_DEFAULT=ASM

ASM_CMAKE_BOOL=	WAVPACK_ENABLE_ASM

.include <bsd.port.mk>
