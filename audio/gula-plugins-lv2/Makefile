PORTNAME=	gula-plugins
DISTVERSION=	g20200606
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of guitar effect LV2 plugins

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/boost/circular_buffer.hpp:devel/boost-libs

USES=		gmake localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	steveb
GH_TAGNAME=	67578fa01a6b1a4d883ab0fe8ceaa4afe4e3af06

CXXFLAGS+=	-fPIC
CXXFLAGS+=	-fbracket-depth=1024 # https://github.com/steveb/gula-plugins/issues/2
MAKE_ARGS=	CXXFLAGS="${CXXFLAGS}"

do-install: # https://github.com/steveb/gula-plugins/issues/3
	cd ${WRKSRC} && ${COPYTREE_SHARE} lv2 ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/*.lv2/*.so

.include <bsd.port.mk>
