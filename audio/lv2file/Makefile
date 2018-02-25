# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	lv2file
DISTVERSION=	0.82-1-19
DISTVERSIONSUFFIX=	-gaed7c77
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
PLIST_FILES=	bin/lv2file man/man1/lv2file.1.gz

post-install:
		${INSTALL_MAN} ${WRKSRC}/debian/lv2file.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lv2file

.include <bsd.port.mk>
