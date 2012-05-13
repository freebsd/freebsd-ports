# New Ports collection makefile for:	simsu
# Date created:		2012-04-21
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	simsu
PORTVERSION=	1.2.2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simsu is a basic Sudoku game

LICENSE=	GPLv3

USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build iconengines imageformats

INSTALLS_ICONS=	yes
HAS_CONFIGURE=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} ${WRKSRC}/${PORTNAME}.pro

CONFIGURE_ENV+=	UIC="${UIC}" QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}"
MAKE_ENV+=	QMAKESPEC="${QMAKESPEC}"

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PORTDATA=	*
PORTDOCS=	CREDITS ChangeLog INSTALL

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Icons
	${CP} -R ${WRKSRC}/icons/hicolor ${PREFIX}/share/icons/

# Pixmaps and Desktop
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}_32.xpm ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.desktop ${PREFIX}/share/applications/

post-install:
# Data
.if !defined (NOPORTDATA)
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "symmetry translations" ${DATADIR})
.endif

# Documentations
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
