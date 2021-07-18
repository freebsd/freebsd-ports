# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	vm
DISTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.com/OpenMusicKontrollers/vm.lv2/-/archive/${DISTVERSION}/
DISTNAME=	vm.lv2-${DISTVERSION}
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual machine LV2 plugin bundle

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		lv2lint:audio/lv2lint
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		compiler:c++11-lib gl meson pkgconfig localbase xorg
USE_XORG=	x11 xext
USE_GL=		gl glew glu

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-extract:
	@${MV} ${WRKDIR}/vm* ${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
