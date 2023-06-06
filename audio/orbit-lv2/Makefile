PORTNAME=	orbit
DISTVERSION=	0.1.661
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin bundle from Open Music Kontrollers
WWW=		https://open-music-kontrollers.ch/lv2/orbit/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint \
		sord_validate:devel/sord

USES=		compiler:c11 meson pkgconfig
PLIST_FILES=	lib/lv2/orbit.lv2/manifest.ttl \
		lib/lv2/orbit.lv2/orbit.so \
		lib/lv2/orbit.lv2/orbit.ttl

USE_GITLAB=	yes
GL_ACCOUNT=	OpenMusicKontrollers
GL_PROJECT=	${PORTNAME}.lv2
GL_COMMIT=	f4aa620fc8d77418856581a6a955192af15b3860

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
