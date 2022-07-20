PORTNAME=	emptyepsilon
DISTVERSIONPREFIX=	EE-
DISTVERSION=	2021.06.23
CATEGORIES=	games

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spaceship bridge simulator game

LICENSE=					GPLv2 AngryFly-Royalty-Free-License
LICENSE_COMB=					multi
LICENSE_NAME_AngryFly-Royalty-Free-License=	AngryFly Royalty-Free-License
LICENSE_FILE_GPLv2=				${WRKSRC}/LICENSE
LICENSE_FILE_AngryFly-Royalty-Free-License=	${WRKSRC}/packs/License.txt
LICENSE_PERMS_AngryFly-Royalty-Free-License=	auto-accept dist-mirror pkg-mirror

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libsfml-system.so:devel/sfml
RUN_DEPENDS=	xclip:x11/xclip

USES=		cmake compiler:c++11-lib gl localbase xorg
USE_GL=		gl glu

USE_GITHUB=	yes
GH_ACCOUNT=	daid
GH_PROJECT=	EmptyEpsilon SeriousProton:sproton

CMAKE_ARGS=	-DSERIOUS_PROTON_DIR="${WRKSRC_sproton}/"

post-patch:
	@${REINPLACE_CMD} -e 's|basepath + |"${DATADIR}/" + basepath + |' \
		${WRKSRC_sproton}/src/resources.cpp
	@${REINPLACE_CMD} -e 's|uint32_t bswap32(uint32_t value)|uint32_t bswap32_(uint32_t value)|' \
		${WRKSRC_sproton}/src/i18n.cpp
	# app uses xclip to read clipboard, ifdef and path need to be corrected
	@${REINPLACE_CMD} -e 's,defined(__APPLE__),& || defined(__FreeBSD__), ; s,"/usr/bin/xclip ,"${PREFIX}/bin/xclip ,' ${WRKSRC_sproton}/src/clipboard.cpp

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/EmptyEpsilon ${STAGEDIR}${PREFIX}/bin/emptyepsilon

.include <bsd.port.mk>
