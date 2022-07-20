PORTNAME=	lv2file
DISTVERSIONPREFIX=	upstream/
DISTVERSION=	0.95
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple program that apples LV2 effects to audio files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libargtable2.so:devel/argtable \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		liblilv-0.so:audio/lilv \
		libsndfile.so:audio/libsndfile \
		libsratom-0.so:audio/sratom

USES=		gmake localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	jeremysalwen

PLIST_FILES=	bin/lv2file

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2file

.include <bsd.port.mk>
