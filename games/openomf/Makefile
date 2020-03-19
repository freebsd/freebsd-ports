# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	openomf
PORTVERSION=	0.6.5
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.omf2097.com/pub/files/omf/:data
DISTFILES+=	omf2097.rar:data
EXTRACT_ONLY=	${DISTFILE_shadow} ${DISTFILE_libdumb} \
		${DISTNAME}.tar.gz

MAINTAINER=	devel@stasyan.com
COMMENT=	Rewritten engine for One Must Fall 2097

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libpng.so:graphics/png \
		libargtable2.so:devel/argtable \
		libenet.so:net/enet
EXTRACT_DEPENDS=	unrar:archivers/unrar

USE_GITHUB=	yes
GH_ACCOUNT=	omf2097
GH_TAGNAME=	c36c421
GH_TUPLE=	omf2097:libShadowDive:b2c34a6:shadow \
		kode54:dumb:238f23c:libdumb

USES=		cmake:insource compiler:c++11-lang gettext openal sdl
USE_SDL=	sdl2

LDFLAGS_i386=	-Wl,-znotext

DESKTOP_ENTRIES="OpenOMF" "" \
		"${PREFIX}/share/openomf/openomf_icon.png " \
		"openomf" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-extract:
	${RMDIR} ${WRKSRC}/external/libShadowDive
	${LN} -s ${WRKSRC_shadow} ${WRKSRC}/external/libShadowDive
	${LN} -s ${WRKSRC_libdumb}/dumb ${WRKSRC}/external/dumb
	${MKDIR} ${WRKDIR}/omf
	cd ${WRKDIR}/omf && unrar e -idq ${DISTDIR}/omf2097.rar

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,"${PREFIX}",g' \
		${WRKSRC}/src/resources/pathmanager.c
.if ${ARCH} != i386
	${REINPLACE_CMD} -e 's,-msse ,,' \
		${WRKSRC}/external/dumb/dumb/cmake/CMakeLists.txt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/openomf ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/resources/openomf_icon.png ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/resources/openomf.bk ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/omf && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
