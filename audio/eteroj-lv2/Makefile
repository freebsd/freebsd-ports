PORTNAME=	eteroj
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://git.open-music-kontrollers.ch/lv2/eteroj.lv2/snapshot/
PKGNAMESUFFIX=	-lv2
DISTNAME=	${PORTNAME}.lv2-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OSC injection/ejection from/to UDP/TCP/Serial for LV2
WWW=		https://open-music-kontrollers.ch/lv2/eteroj/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint
LIB_DEPENDS=	libsratom-0.so:audio/sratom \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libuv.so:devel/libuv

USES=		compiler:c11 meson pkgconfig tar:xz

PLIST_FILES=	lib/lv2/eteroj.lv2/eteroj.so \
		lib/lv2/eteroj.lv2/eteroj.ttl \
		lib/lv2/eteroj.lv2/manifest.ttl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
