PORTNAME=	noise-repellent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin for broadband noise reduction

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libspecbleach.so:audio/libspecbleach

USES=		meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	lucianodato

.include <bsd.port.mk>
