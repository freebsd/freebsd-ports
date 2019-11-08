# $FreeBSD$

PORTNAME=	netpanzer
PORTVERSION=	0.8.7
DISTVERSIONSUFFIX=	-source
CATEGORIES=	games
MASTER_SITES=	http://www.netpanzer.info/Download/NetPanzer/Releases/${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Real time, isometric view, tank multiplayer strategy game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LDFLAGS+=	-lpthreads

USES=		gnome scons sdl zip
USE_SDL=	sdl mixer image
USE_GNOME=	libxml2
MAKE_ARGS+=	datadir="${DATADIR}"
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/netpanzer \
		share/applications/netpanzer.desktop \
		share/pixmaps/netpanzer.png \
		share/pixmaps/netpanzer.xpm

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netpanzer ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "cache maps pics powerups scripts sound units wads" \
		${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/support/win32/netpanzer.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/netpanzer.png ${WRKSRC}/support/icon/netpanzer.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} COPYING README ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} code-notes.txt coding.txt old/serverhowto.html \
		${STAGEDIR}${DOCSDIR})

do-fetch-svn:
	svn export svn://svn.berlios.de/${PORTNAME}/tags/${PORTNAME}/${PORTVERSION} ${PORTNAME}-${PORTVERSION}
	tar cjf ${PORTNAME}-${PORTVERSION}.tar.bz2 ${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
