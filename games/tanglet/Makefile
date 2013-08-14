# New Ports collection makefile for:	tanglet
# Date created:		2012-04-21
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	tanglet
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Single player word finding game based on Boggle

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT4=	moc_build qmake_build rcc_build gui
INSTALLS_ICONS=	yes

PORTDOCS=	CREDITS ChangeLog

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

post-install:
# Pixmaps
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
