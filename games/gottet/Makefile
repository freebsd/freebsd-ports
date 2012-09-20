# New Ports collection makefile for:	gottet
# Date created:		21 April 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	gottet
PORTVERSION=	1.0.4
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A Tetris clone

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT4=	moc_build qmake_build rcc_build iconengines imageformats
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	ChangeLog

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/applications

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Pixmaps and Desktop
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.desktop ${PREFIX}/share/applications/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
