# $FreeBSD$

PORTNAME=	geonkick
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.2
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software percussion synthesizer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		gmake:devel/gmake \
		rapidjson>0:devel/rapidjson \
		${LOCALBASE}/lib/libredkite.a:x11-toolkits/redkite
LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++17-lang cmake desktop-file-utils gnome localbase:ldflags \
		pkgconfig shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	iurie-sw
USE_GNOME=	cairo
USE_XORG=	x11

INSTALLS_ICONS=	yes

.include <bsd.port.mk>
