PORTNAME=	vm
DISTVERSION=	0.14.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://git.open-music-kontrollers.ch/lv2/vm.lv2/snapshot/
PKGNAMESUFFIX=	-lv2
DISTNAME=	${PORTNAME}.lv2-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual machine LV2 plugin bundle
WWW=		https://open-music-kontrollers.ch/lv2/vm/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		compiler:c++11-lib gl meson pkgconfig localbase tar:xz xorg
USE_GL=		gl glew glu
USE_XORG=	x11 xext

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
