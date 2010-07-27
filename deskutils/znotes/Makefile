# New ports collection makefile for:	znotes
# Date created:		2009-11-12
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	znotes
PORTVERSION=	0.4.3
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Simple notes based on QT4

USE_QT_VER=	4
QT_COMPONENTS=	gui network xml qmake_build uic_build moc_build rcc_build \
		linguist_build

LICENSE=	GPLv3

DESKTOP_ENTRIES="zNotes" "Simple notes" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"Utility;TextEditor;Qt;" ${FALSE}

OPTIONS=	NLS		"Build with NLS support" on

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

post-patch:
	    @${REINPLACE_CMD} -e 's|lrelease|lrelease-qt4|g' \
		${WRKSRC}/${PORTNAME}.pro
	    @${REINPLACE_CMD} -i -e 's,QCoreApplication::applicationDirPath()+"/translations","${DATADIR}/translations",g' \
		${WRKSRC}/settings.cpp

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if defined(WITH_NLS)
	${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${DATADIR}/translations
PLIST_FILES+=	%%DATADIR%%/translations/${PORTNAME}_cs.qm \
		%%DATADIR%%/translations/${PORTNAME}_ru.qm \
		%%DATADIR%%/translations/${PORTNAME}_pt_BR.qm \
		%%DATADIR%%/translations/${PORTNAME}_uk.qm
PLIST_DIRS+=	%%DATADIR%%/translations \
		%%DATADIR%%
.else
.endif

.include <bsd.port.post.mk>
