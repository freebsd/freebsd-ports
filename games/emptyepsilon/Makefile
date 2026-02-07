PORTNAME=	emptyepsilon
DISTVERSIONPREFIX=	EE-
DISTVERSION=	2024.12.08
CATEGORIES=	games

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spaceship bridge simulator game
WWW=		https://daid.github.io/EmptyEpsilon/ \
		https://github.com/daid/EmptyEpsilon \
		https://github.com/daid/SeriousProton

LICENSE=					GPLv2 AngryFly-Royalty-Free-License
LICENSE_COMB=					multi
LICENSE_NAME_AngryFly-Royalty-Free-License=	AngryFly Royalty-Free-License
LICENSE_FILE_GPLv2=				${WRKSRC}/LICENSE
LICENSE_FILE_AngryFly-Royalty-Free-License=	${WRKSRC}/packs/License.txt
LICENSE_PERMS_AngryFly-Royalty-Free-License=	auto-accept dist-mirror pkg-mirror

# BUILD_DEPENDS for glm is commented out because the system glm (1.0.x) is
# incompatible with EmptyEpsilon's code. The bundled glm 0.9.9.8 is used instead
# via git submodule to avoid API incompatibilities (missing radians, degrees,
# u8vec4, vec3 functions/types in newer glm versions).
#BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libsfml-system.so:devel/sfml \
		libmeshoptimizer.so:misc/meshoptimizer \
		libopus.so:audio/opus
RUN_DEPENDS=	xclip:x11/xclip

USES=		cmake:insource compiler:c++11-lib localbase:ldflags pkgconfig python:build sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	daid
GH_PROJECT=	EmptyEpsilon
GH_TUPLE=	daid:SeriousProton:${DISTVERSIONFULL}:sproton/sproton \
		BinomialLLC:basis_universal:v1_15_update2:basis/SeriousProton/externals/basis \
		g-truc:glm:0.9.9.8:glm/sproton/libs/glm

CMAKE_ARGS=	-DSERIOUS_PROTON_DIR="${WRKSRC}/sproton" \
		-DWITH_OPUS=system \
		-DWITH_GLM=bundled
CXXFLAGS+=	-DGLM_ENABLE_EXPERIMENTAL

post-patch:
	@${REINPLACE_CMD} -e 's|basepath + |"${DATADIR}/" + basepath + |' \
		${WRKSRC_sproton}/src/resources.cpp
	@${REINPLACE_CMD} -e 's|uint32_t bswap32(uint32_t value)|uint32_t bswap32_(uint32_t value)|' \
		${WRKSRC_sproton}/src/i18n.cpp

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/EmptyEpsilon ${STAGEDIR}${PREFIX}/bin/emptyepsilon

.include <bsd.port.mk>
