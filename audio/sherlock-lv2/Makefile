# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	sherlock
PORTVERSION=	0.14.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Investigative LV2 plugin bundle

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to build: cc1: unrecognized command line option -std=gnu11

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers
GH_PROJECT=	sherlock.lv2
USE_XORG=	x11 xext
USE_GL=		gl glu

.include <bsd.port.mk>
