# $FreeBSD$

PORTNAME=	qtemu
PORTVERSION=	1.0.5
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 based frontend for QEMU

USE_QT4=	gui xml uic_build moc_build rcc_build
USES=		qmake tar:bzip2
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

DESKTOP_ENTRIES="QtEmu" "QEMU frontend" "" \
		"qtemu" "" true

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USE=	QT4=linguisttools_build

.include <bsd.port.options.mk>

post-configure:
.if ${PORT_OPTIONS:MNLS}
	(cd ${WRKSRC} && ${LRELEASE} qtemu.pro)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtemu ${STAGEDIR}${PREFIX}/bin/qtemu
.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/qtemu*.qm ${STAGEDIR}${DATADIR}/translations
.endif
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/help && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
