# Ports collection Makefile for:	cutemaze
# Date created:				2012-04-20
# Whom:					nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	cutemaze
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A simple, top-down game in which mazes are randomly generated

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats
INSTALLS_ICONS=	yes

MAKE_JOBS_SAFE=	yes

PORTDATA=	*
PORTDOCS=	ChangeLog README

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "preview themes" ${DATADIR})

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

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
