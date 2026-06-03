PORTNAME=	screcord
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 capture plugin
WWW=		https://github.com/brummer10/screcord.lv2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	${PORTNAME}.lv2
BUILD_WRKSRC=	${WRKSRC}/screcord
ALL_TARGET=	nogui

PLIST_FILES=	lib/lv2/sc_record.lv2/manifest.ttl \
		lib/lv2/sc_record.lv2/sc_record.so \
		lib/lv2/sc_record.lv2/sc_record.ttl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/lv2/sc_record.lv2
	${INSTALL_DATA} ${WRKSRC}/screcord/manifest.ttl \
		${STAGEDIR}${PREFIX}/lib/lv2/sc_record.lv2/
	${INSTALL_DATA} ${WRKSRC}/screcord/sc_record.ttl \
		${STAGEDIR}${PREFIX}/lib/lv2/sc_record.lv2/
	${INSTALL_LIB} ${WRKSRC}/screcord/sc_record.so \
		${STAGEDIR}${PREFIX}/lib/lv2/sc_record.lv2/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/sc_record.lv2/sc_record.so

.include <bsd.port.mk>
