# $FreeBSD$

PORTNAME=	tamgamp
DISTVERSION=	g20200514
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	04c59043ab0939dff5a11698704d15289931bd2e.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 guitar amp simulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libzita-resampler.so:audio/zita-resampler

USES=		gmake localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sadko4u
GH_PROJECT=	tamgamp.lv2
GH_TAGNAME=	590ced0a1da96ca481a1a719eebdb17f3af472e4

BINARY_ALIAS=	make=${GMAKE} # https://github.com/sadko4u/tamgamp.lv2/issues/8

PLIST_FILES=	lib/lv2/tamgamp.lv2/manifest.ttl \
		lib/lv2/tamgamp.lv2/tamgamp-lv2.so \
		lib/lv2/tamgamp.lv2/tamgamp.ttl \
		lib/lv2/tamgamp.lv2/tamgamp_gx.ttl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/tamgamp.lv2/tamgamp-lv2.so

.include <bsd.port.mk>
