# $FreeBSD$

PORTNAME=	simsu
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Basic Sudoku game

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

PORTDATA=	*
PORTDOCS=	CREDITS ChangeLog

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

post-install:
# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/hicolor/48x48/apps/simsu.png ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
