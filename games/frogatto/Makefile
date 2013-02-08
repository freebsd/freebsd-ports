# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frogatto
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GH

MAINTAINER=	fiziologus@gmail.com
COMMENT=	An old-school 2D classic adventure platformer game

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		png15:${PORTSDIR}/graphics/png

NO_PACKAGE=	Package will be 144M, set FORCE_PACKAGE if you really want it

USE_GITHUB=	yes
GH_ACCOUNT=	frogatto
GH_PROGECT=	frogatto
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	64c84bf

USE_GMAKE=	yes
ALL_TARGET=	game server
USE_GL=		glew
USE_SDL=	image mixer ttf

PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}-server

post-patch:
# Sanitize Makefile: honor CC/CXX and C[XX]FLAGS, trim `-mt' suffix from boost
# libraries, remove superfluous libraries when linking server executable (add
# missing -pthread instead), etc.
	@${REINPLACE_CMD} -E -e 's,= (ccache )?gcc,:= $$(CC) $$(CFLAGS),' \
		-e 's,= (ccache )?g\+\+,:= $$(CXX) $$(CXXFLAGS),' \
		-e 's, -O2,, ; s, -g,, ; s, -L/usr/lib,, ; s, -L/sw/lib,,' \
		-e '/server/s,`.*mixer,-L${LOCALBASE}/lib ${PTHREAD_LIBS},' \
		-e 's,-mt,,g' -e 's,-lpng,-lpng15,g' ${WRKSRC}/Makefile
# Point to the right location where to look for resources on FreeBSD
	@${REINPLACE_CMD} -e 's,HAVE_CONFIG_H,__FreeBSD__,' \
		-e 's,DATADIR,"${DATADIR}",' ${WRKSRC}/src/filesystem.cpp
	@${REINPLACE_CMD} -E 's,(music|sounds)/,${DATADIR}/&,' \
		${WRKSRC}/src/sound.cpp
	@${REINPLACE_CMD} -e '/\/locale\//s,\.,${PREFIX}/share,' \
		${WRKSRC}/src/i18n.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/game ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/server ${PREFIX}/bin/${PORTNAME}-server
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data images music sounds" \
		${DATADIR}
	cd ${WRKSRC}/locale && ${MV} hu_HU hu && ${MV} ms_MY ms
	cd ${WRKSRC} && ${COPYTREE_SHARE} "locale" ${PREFIX}/share
# Fix permissions on DATADIR after COPYTREE_SHARE (cpio(1) defaults to 700
# if target directory (${DATADIR}) does not exist)
	@${CHMOD} 755 ${DATADIR}
# Dynamically generate part of the PLIST for NLS files and game resources
# (lots of them)
	@${FIND} ${PREFIX}/share/locale -name ${PORTNAME}.mo | \
		${SED} 's,^${PREFIX}/,,' | ${SORT} >> ${TMPPLIST}
	@${FIND} ${DATADIR} -not -type d | \
		${SED} 's,^${PREFIX}/,,' | ${SORT} >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | \
		${SED} 's,^${PREFIX}/,@dirrm ,' | ${SORT} -r >> ${TMPPLIST}

.include <bsd.port.mk>
