# $FreeBSD$

PORTNAME=	screcord
DISTVERSION=	g20171206
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 capture plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	${PORTNAME}.lv2
GH_TAGNAME=	36fbff9

PLIST_FILES=	lib/lv2/sc_record.lv2/manifest.ttl \
		lib/lv2/sc_record.lv2/sc_record.so \
		lib/lv2/sc_record.lv2/sc_record.ttl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/sc_record.lv2/sc_record.so

.include <bsd.port.mk>
