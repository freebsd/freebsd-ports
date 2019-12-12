# $FreeBSD$

PORTNAME=	midiomatic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-beta2-3
DISTVERSIONSUFFIX=	-ga9649cd
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of MIDI filter, generator and processor plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash

USES=		compiler:c++0x gmake pkgconfig shebangfix
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	SpotlightKid
GH_TUPLE=	DISTRHO:DPF:30ba386:dpf/dpf

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vst

.include <bsd.port.mk>
