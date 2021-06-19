# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	sherlock
DISTVERSION=	0.28.0
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Investigative LV2 plugin bundle

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		compiler:c11 gl meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMusicKontrollers
GH_PROJECT=	sherlock.lv2
USE_XORG=	x11 xext
USE_GL=		gl glew glu

.include <bsd.port.mk>
