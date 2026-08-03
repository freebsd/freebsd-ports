PORTNAME=	vamp-plugin-sdk
DISTVERSION=	2.10.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/vamp-plugins/vamp-plugin-sdk/releases/download/vamp-plugin-sdk-v${DISTVERSION:R}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vamp audio analysis plugin SDK
WWW=		https://www.vamp-plugins.org/ \
		https://github.com/vamp-plugins/vamp-plugin-sdk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gmake pkgconfig
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/vamp/*.so

.include <bsd.port.mk>
