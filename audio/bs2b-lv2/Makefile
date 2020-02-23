# $FreeBSD$

PORTNAME=	bs2b
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin for using Bauer stereophonic-to-binaural DSP library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lvtk>0:audio/lvtk
LIB_DEPENDS=	libbs2b.so:audio/libbs2b

USES=		pkgconfig python:2.7,build waf
USE_GITHUB=	yes
GH_ACCOUNT=	nilninull
GH_PROJECT=	${PORTNAME}-lv2

PLIST_FILES=	lib/lv2/bs2b.lv2/bs2b.so \
		lib/lv2/bs2b.lv2/bs2b.ttl \
		lib/lv2/bs2b.lv2/bs2b_presets.ttl \
		lib/lv2/bs2b.lv2/manifest.ttl

post-patch:
	@${REINPLACE_CMD} -e "s|'/usr/lib/lv2'|'${PREFIX}/lib/lv2'|" ${WRKSRC}/wscript

.include <bsd.port.mk>
