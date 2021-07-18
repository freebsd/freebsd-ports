PORTNAME=	bshapr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Beat/envelope shaper LV2 plugin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		cmake:devel/cmake

USES=		compiler:c++11-lang gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sjaehn
GH_PROJECT=	BShapr
USE_GNOME=	cairo
USE_XORG=	x11

MAKEFILE=	makefile

MAKE_JOBS_UNSAFE=	yes # workaround for intermittent build failures: https://github.com/sjaehn/BShapr/issues/18

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/BShapr.lv2/*.so

.include <bsd.port.mk>
