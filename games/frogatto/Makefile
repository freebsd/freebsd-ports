# New ports collection makefile for:	Frogatto
# Date created:				14 Jul 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frogatto
PORTVERSION=	1.0
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
		-e 's,-mt,,g ; /server/s,`.*mixer,,' \
		-e '/server/s,-lX11,,' ${WRKSRC}/Makefile
# Point to the right location where look for the resources on FreeBSD
	@${REINPLACE_CMD} -e 's,HAVE_CONFIG_H,__FreeBSD__,' \
		-e 's,DATADIR,"${DATADIR}",' ${WRKSRC}/src/filesystem.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/game ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/server ${PREFIX}/bin/${PORTNAME}-server
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data images music sounds" \
		${DATADIR}
# Dynamically generate part of the PLIST for game resources (lots of them)
	${FIND} ${DATADIR} -not -type d | \
		${SED} 's,^${PREFIX}/,,' | ${SORT} >> ${TMPPLIST}
	${FIND} ${DATADIR} -type d | \
		${SED} 's,^${PREFIX}/,@dirrm ,' | ${SORT} -r >> ${TMPPLIST}

.include <bsd.port.mk>
