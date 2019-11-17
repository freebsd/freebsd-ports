# $FreeBSD$

PORTNAME=	stone-phaser
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2-5
DISTVERSIONSUFFIX=	-g3e51889
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classic analog phaser effect, made with DPF and Faust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash

USES=		gmake gnome pkgconfig shebangfix xorg
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	jpcima
GH_TUPLE=	DISTRHO:DPF:e69074e:dpf/dpf
USE_GNOME=	cairo
USE_XORG=	x11

MAKE_ARGS=	BUILD_LADSPA=false
CFLAGS+=	-I${FILESDIR}

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst

.include <bsd.port.mk>
