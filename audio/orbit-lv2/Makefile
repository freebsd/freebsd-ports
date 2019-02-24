# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	orbit
PORTVERSION=	0.1.431
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.com/OpenMusicKontrollers/orbit.lv2/repository/archive.tar.gz?ref=aca0b7a&dummy=/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin bundle from Open Music Kontrollers

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		cmake compiler:c11 pkgconfig
PLIST_FILES=	lib/lv2/orbit.lv2/manifest.ttl \
		lib/lv2/orbit.lv2/orbit.so \
		lib/lv2/orbit.lv2/orbit.ttl

post-extract:
	@${MV} ${WRKDIR}/orbit* ${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
