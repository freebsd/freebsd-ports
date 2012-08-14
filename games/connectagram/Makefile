# New Ports collection makefile for:	connectagram
# Date created:		23 April 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	connectagram
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Word unscrambling game

LICENSE=	GPLv3

OPTIONS_DEFINE=	DATA
OPTIONS_DEFAULT=	DATA

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build corelib gui iconengines imageformats network
INSTALLS_ICONS=	yes

MAKE_JOBS_SAFE=	yes

PORTDATA=	*
PORTDOCS=	ChangeLog INSTALL

PLIST_FILES=	bin/connectagram \
	share/applications/connectagram.desktop \
	share/icons/hicolor/48x48/apps/connectagram.png

PLIST_DIRSTRY=	share/icons/hicolor/48x48/apps \
	share/icons/hicolor/48x48 \
	share/icons/hicolor \
	share/icons \
	share/applications

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

.include <bsd.port.options.mk>

post-install:
# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
