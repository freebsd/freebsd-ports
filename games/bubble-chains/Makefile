# New ports collection makefile for:	bubble-chains
# Date created:		2012-04-21
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	bubble-chains
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://bubble-chains.sintegrial.com/files/
DISTNAME=	chains-${DISTVERSION}
EXTRACT_SUFX=	-src.7z

MAINTAINER=	nemysis@gmx.ch
COMMENT=	The aim is to remove all of the targets on each level

LICENSE=	GPLv2

EXTRACT_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip
BUILD_DEPENDS=		7z:${PORTSDIR}/archivers/p7zip

WRKSRC=		${WRKDIR}/chains-${PORTVERSION}-src

USE_SDL=	sdl image mixer
USE_GL=		glut glew glu
USE_XORG=	xrandr
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats \
		corelib svg xml opengl network

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/bubble-chains \
		share/pixmaps/bubble-chains.ico \
		share/pixmaps/bubble-chains.png
PLIST_DIRSTRY=	share/applications

PORTDATA=	*
PORTDOCS=	README

P7ZIP_CMD=	${LOCALBASE}/bin/7z
P7ZIP_ARGS=	x -o${WRKDIR}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${P7ZIP_CMD} ${P7ZIP_ARGS} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/chains|${DATADIR}|' \
		${WRKSRC}/main.cpp ${WRKSRC}/Game.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chains ${PREFIX}/bin/${PORTNAME}

# Pixmaps and Desktop
	${INSTALL_DATA} ${WRKSRC}/images/logo.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/icon.ico \
		${PREFIX}/share/pixmaps/${PORTNAME}.ico

# Data
.if !defined (NOPORTDATA)
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
.endif

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
