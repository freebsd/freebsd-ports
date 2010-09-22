# New ports collection makefile for:	Frogatto & Friends
# Date created:				14 Jul 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frogatto
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	http://www.frogatto.com/files/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An old-school 2D classic adventure platformer game

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GCC=	4.2+	# required for `-fthreadsafe-statics' on FreeBSD 6.X
USE_GMAKE=	yes
ALL_TARGET=	game server
USE_GL=		glew
USE_SDL=	image mixer ttf

PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}-server

post-patch:
# Sanitize Makefile: honor CXX/CXXFLAGS, trim `-mt' suffix from boost libs,
# remove superfluous libraries when linking server executable, etc.
	@${REINPLACE_CMD} -E -e 's,(ccache )?g\+\+,$$(CXX) $$(CXXFLAGS),' \
		-e 's,-O2,, ; s,-g,, ; s,/usr/X11R6,${LOCALBASE},' \
		-e 's,-mt,,g ; /server/s,`.*mixer,${PTHREAD_LIBS},' \
		-e 's,-L/usr/lib,, ; s,-L/sw/lib,,' \
		-e '/server/s,-lX11,,' ${WRKSRC}/Makefile
# Point to the right location where to look for resources on FreeBSD
	@${REINPLACE_CMD} -e 's,HAVE_CONFIG_H,__FreeBSD__,' \
		-e 's,DATADIR,"${DATADIR}",' ${WRKSRC}/src/filesystem.cpp
	@${REINPLACE_CMD} -E 's,(music|sounds)/,${DATADIR}/&,' \
		${WRKSRC}/src/sound.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/game ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/server ${PREFIX}/bin/${PORTNAME}-server
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data images music sounds" \
		${DATADIR}
# Fix permissions on DATADIR after COPYTREE_SHARE (cpio(1) defaults to 700
# if target directory (${DATADIR}) does not exist)
	@${CHMOD} 755 ${DATADIR}
# Dynamically generate part of the PLIST for game resources (lots of them)
	@${FIND} ${DATADIR} -not -type d | \
		${SED} 's,^${PREFIX}/,,' | ${SORT} >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | \
		${SED} 's,^${PREFIX}/,@dirrm ,' | ${SORT} -r >> ${TMPPLIST}

.include <bsd.port.mk>
