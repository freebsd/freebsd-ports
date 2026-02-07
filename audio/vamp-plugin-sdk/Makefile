PORTNAME=	vamp-plugin-sdk
DISTVERSION=	2.9.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/2588/

MAINTAINER=	uddka@student.kit.edu
COMMENT=	Vamp audio analysis plugin SDK
WWW=		https://www.vamp-plugins.org/

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
