# $FreeBSD$

PORTNAME=	netpanzer
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	LOCAL/madpilot/netpanzer

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Real time, isometric view, tank multiplayer strategy game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LDFLAGS+=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}

USE_BZIP2=	yes
USE_SDL=	sdl mixer image
USE_GNOME=	libxml2
USE_SCONS=	yes
SCONS_ARGS+=	datadir="${DATADIR}"
SCONS_BUILDENV=	${SCONS_ENV}

PORTDOCS=	*
PORTDATA=	*
MAN6=		netpanzer.6

post-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netpanzer ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "cache maps pics powerups scripts sound units wads"  ${DATADIR})
	${INSTALL_MAN} ${WRKSRC}/docs/netpanzer.6 ${MANPREFIX}/man/man6
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/netpanzer.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/netpanzer.png ${WRKSRC}/netpanzer.xpm ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} COPYING ChangeLog README RELNOTES TODO ${DOCSDIR})
	(cd ${WRKSRC}/docs && ${INSTALL_MAN} Doxyfile code-notes.txt coding.txt serverhowto.html tipofday.txt ${DOCSDIR})
.endif

do-fetch-svn:
	svn export svn://svn.berlios.de/${PORTNAME}/tags/${PORTNAME}/${PORTVERSION} ${PORTNAME}-${PORTVERSION}
	tar cjf ${PORTNAME}-${PORTVERSION}.tar.bz2 ${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
