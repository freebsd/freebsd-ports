# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qrfcview
PORTVERSION=	0.62
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	BERLIOS

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical RFC viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmake tar:tgz
USE_QT4=	gui network corelib uic_build moc_build rcc_build

SUB_FILES=	qRFCView

PLIST_FILES=	bin/qRFCView \
		libexec/qRFCView \
		bin/qrfcview \
		share/pixmaps/qrfcview.png
PORTDOCS=	*

DESKTOP_ENTRIES="qRFCView" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"qRFCView" \
		"Utility;TextTools;Qt;" \
		""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qRFCView ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/qRFCView ${STAGEDIR}${PREFIX}/bin/
	${LN} -s qRFCView ${STAGEDIR}${PREFIX}/bin/qrfcview
	${INSTALL_DATA} ${WRKSRC}/images/rfcview.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
