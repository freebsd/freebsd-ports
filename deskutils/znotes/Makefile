# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	znotes
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Simple notes based on QT4

LICENSE=	GPLv3

USE_QT4=	gui network xml qmake_build uic_build moc_build rcc_build \
		linguist_build

DESKTOP_ENTRIES="zNotes" "Simple notes" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"Utility;TextEditor;Qt;" ${FALSE}

OPTIONS_DEFINE=		NLS

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

post-patch:
	    @${REINPLACE_CMD} -e 's|lrelease|lrelease-qt4|g' \
		${WRKSRC}/${PORTNAME}.pro
	    @${REINPLACE_CMD} -i -e 's,QCoreApplication::applicationDirPath()+"/translations","${DATADIR}/translations",g' \
		${WRKSRC}/settings.cpp

.include <bsd.port.options.mk>

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${DATADIR}/translations
PLIST_FILES+=	%%DATADIR%%/translations/${PORTNAME}_cs.qm \
		%%DATADIR%%/translations/${PORTNAME}_es.qm \
		%%DATADIR%%/translations/${PORTNAME}_en.qm \
		%%DATADIR%%/translations/${PORTNAME}_ru.qm \
		%%DATADIR%%/translations/${PORTNAME}_sk.qm \
		%%DATADIR%%/translations/${PORTNAME}_pt_BR.qm \
		%%DATADIR%%/translations/${PORTNAME}_uk.qm

PLIST_DIRS+=	%%DATADIR%%/translations \
		%%DATADIR%%
.else
.endif

.include <bsd.port.mk>
