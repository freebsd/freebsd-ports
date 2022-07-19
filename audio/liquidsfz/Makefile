PORTNAME=	liquidsfz
DISTVERSION=	0.3.0-2
DISTVERSIONSUFFIX=	-g82ce2bb
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sampler that can load and play .sfz files, includes the LV2 pugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile

USES=		autoreconf compiler:c++17-lang gmake libtool pkgconfig readline
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	swesterfeld

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/liquidsfz \
		include/liquidsfz.hh \
		lib/libliquidsfz.so \
		lib/libliquidsfz.so.3 \
		lib/libliquidsfz.so.3.0.0 \
		lib/lv2/liquidsfz.lv2/liquidsfz.ttl \
		lib/lv2/liquidsfz.lv2/liquidsfz_lv2.so \
		lib/lv2/liquidsfz.lv2/manifest.ttl \
		libdata/pkgconfig/liquidsfz.pc

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Duint=unsigned -Dregister=registerx
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/liquidsfz.lv2/liquidsfz_lv2.so

.include <bsd.port.post.mk>
