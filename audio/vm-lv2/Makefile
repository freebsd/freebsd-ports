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
USE_XORG=	x11 xext
USE_GL=		gl glew glu

.include <bsd.port.mk>
