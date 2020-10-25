# $FreeBSD$

PORTNAME=	liquidsfz
DISTVERSION=	0.2.1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	18e59d6784f32e4d9c25c0f8ccbc9e7d9cd4c865.patch:-p1 # use cut instead of sed for version splitting
PATCHFILES+=	217b71d4d8e931e8dd4954a3b1e1e58d8cb5f585.patch:-p1 # LIB: Voice: add missing include

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
		lib/libliquidsfz.so.2 \
		lib/libliquidsfz.so.2.0.1 \
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
