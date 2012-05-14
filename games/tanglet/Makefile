# New Ports collection makefile for:	tanglet
# Date created:		2012-04-21
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	tanglet
PORTVERSION=	1.2.1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tanglet is a single player word finding game based on Boggle

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build corelib gui iconengines imageformats
INSTALLS_ICONS=	yes

MAKE_JOBS_SAFE=	yes

PORTDATA=	*
PORTDOCS=	CREDITS ChangeLog INSTALL

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Icons
	cd ${WRKSRC}/icons && ${FIND} hicolor -type d -name apps -exec \
		${MKDIR} ${PREFIX}/share/icons/{} \;
	cd ${WRKSRC}/icons && ${FIND} hicolor -type f -exec \
		${INSTALL_DATA} {} ${PREFIX}/share/icons/{} \;

# Pixmaps and Desktop
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}_32.xpm ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}.desktop ${PREFIX}/share/applications/

# Data
.if !defined(NOPORTDATA)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data translations" ${DATADIR})
.endif

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
