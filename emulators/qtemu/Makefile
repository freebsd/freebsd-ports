# $FreeBSD$

PORTNAME=	qtemu
PORTVERSION=	1.0.5
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt 4 based frontend for QEMU

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake tar:bzip2
USE_QT4=	gui xml uic_build moc_build rcc_build
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}

DESKTOP_ENTRIES="QtEmu" "QEMU frontend" "" \
		"qtemu" "" true

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USE=	QT4=linguisttools_build

post-configure-NLS-on:
	(cd ${WRKSRC} && ${LRELEASE} qtemu.pro)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtemu ${STAGEDIR}${PREFIX}/bin/qtemu

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/qtemu*.qm ${STAGEDIR}${DATADIR}/translations

do-install-DOCS-on:
	(cd ${WRKSRC}/help && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
