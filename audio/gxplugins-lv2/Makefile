PORTNAME=	gxplugins
DISTVERSION=	0.9
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2
MASTER_SITES=	https://github.com/brummer10/GxPlugins.lv2/files/6329721/
DISTNAME=	GxPlugins_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of LV2 plugins from the guitarix project

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		compiler:c++11-lang gettext-runtime gmake gnome localbase \
		pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

MAKE_ENV=	PATH=${LOCALBASE}/bin:/usr/bin:/bin CXXFLAGS="${CXXFLAGS}" # 'ld' needs to be first in the path on 12, -B{path} isn't sufficient for some reason
LDFLAGS+=	-B${LOCALBASE}/bin # Use ld provided by USE_BINUTILS for GNU features, otherwise GNU ld isn't called

post-patch:
	# SIMD level is wrongly determined during build, not during run: https://github.com/brummer10/GxPlugins.lv2/issues/8
	@${REINPLACE_CMD} -E ' \
		s|shell cat /proc/cpuinfo|shell echo ""|; \
		s| -fstrength-reduce||; \
		s| -O2||; s| -Wl,-z,nodelete||; \
		s|INSTALL_DIR = .*|INSTALL_DIR = ${PREFIX}/lib/lv2|' \
		${WRKSRC}/*/Makefile

.include <bsd.port.mk>
