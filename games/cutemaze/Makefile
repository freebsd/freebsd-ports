# Ports collection Makefile for:	cutemaze
# Date created:				2012-04-20
# Whom:					nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	cutemaze
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Is a simple, top-down game in which mazes are randomly generated

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build iconengines imageformats
INSTALLS_ICONS=	yes

MAKE_JOBS_SAFE=	yes

PORTDATA=	*
PORTDOCS=	ChangeLog README

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Icons
	${MKDIR} ${PREFIX}/share/icons/oxygen
.for d in icons
	(cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} oxygen ${PREFIX}/share/icons/)
.endfor

# Pixmaps and Desktop
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.desktop \
		${PREFIX}/share/applications/

# Data
.if !defined (NOPORTDATA)
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "preview themes" ${DATADIR})
.endif

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
