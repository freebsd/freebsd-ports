PORTNAME=	keeperrl
PORTVERSION=	0.0.${ALPHA_VERSION}
PORTREVISION=	5
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	c0fc69cbee72.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ambitious dungeon builder with roguelike elements

LICENSE=	GPLv2 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.txt
LICENSE_FILE_OFL11=	${WRKSRC}/data_contrib/SIL_Open_Font_License.txt

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libcurl.so:ftp/curl

USES=		compiler:c++14-lang gl gmake localbase openal sdl

USE_GITHUB=	yes
GH_ACCOUNT=	miki151
GH_TAGNAME=	alpha${ALPHA_VERSION}
USE_GL=		gl
USE_SDL=	sdl2 image2

ALPHA_VERSION=	23
LIBS+=		-lexecinfo
MAKE_ARGS=	DATA_DIR="${DATADIR}" GCC="${CXX}" \
		LDFLAGS="${LDFLAGS}" RELEASE=true
# USE_GCC adds -Wl,-rpath=${_GCC_RUNTIME} which breaks -x c++-header
MAKE_ARGS+=	PCH= PCHINC=

LDFLAGS_i386=	-Wl,-znotext

DESKTOP_ENTRIES="KeeperRL" "" "" "keeper" \
		"Game;Simulation;" false

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS =/ s|=|= ${CFLAGS}|' \
		-e '/^LIBS =/ s|$$| ${LIBS}|' \
		-e 's|bash|sh|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|bash|sh|' ${WRKSRC}/check_serial.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keeper ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data_contrib data_free" \
		${STAGEDIR}${DATADIR} "! -name *License.txt"

.include <bsd.port.mk>
