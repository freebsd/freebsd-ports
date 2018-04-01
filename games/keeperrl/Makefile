# $FreeBSD$

PORTNAME=	keeperrl
PORTVERSION=	0.0.${ALPHA_VERSION}
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	games@FreeBSD.org
COMMENT=	Ambitious dungeon builder with roguelike elements

LICENSE=	GPLv2 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.txt
LICENSE_FILE_OFL11=	${WRKSRC}/data_contrib/SIL_Open_Font_License.txt

BROKEN_FreeBSD_10=	needs c++14, does not build even with clang5

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libcurl.so:ftp/curl

USES=		gmake localbase openal

USE_GITHUB=	yes
GH_ACCOUNT=	miki151
GH_TAGNAME=	alpha${ALPHA_VERSION}
USE_GL=		gl
USE_SDL=	sdl2 image2

ALPHA_VERSION=	23
NO_CONFIGURE=	yes
LIBS+=		-lexecinfo
LLD_UNSAFE=	yes
MAKE_ARGS=	DATA_DIR="${DATADIR}" GCC="${CXX}" \
		LDFLAGS="${LDFLAGS}" RELEASE=true

DESKTOP_ENTRIES="KeeperRL" "" "" "keeper" \
		"Game;Simulation;" false

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS =/ s|=|= ${CFLAGS}|' \
		-e '/^LIBS =/ s|$$| ${LIBS}|' \
		-e 's|bash|sh|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|bash|sh|' ${WRKSRC}/check_serial.sh
	@${REINPLACE_CMD} '/_GLIBCXX_END_NAMESPACE_VERSION/d' \
		${WRKSRC}/extern/iomanip.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keeper ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data_contrib data_free" \
		${STAGEDIR}${DATADIR} "! -name *License.txt"

.include <bsd.port.mk>
