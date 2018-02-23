# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	znotes
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple notes managment application based on Qt 4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmake
USE_QT4=	corelib gui network xml uic_build moc_build rcc_build \
		linguisttools_build
QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE}

DESKTOP_ENTRIES="zNotes" "Notes managment" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"Utility;TextEditor;Qt;" true

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

post-patch:
	@${REINPLACE_CMD} -e '/.path =/s|/usr|$$$$PREFIX|g' \
		-e '/PREFIX = /d' \
		${WRKSRC}/${PORTNAME}.pro
	@${REINPLACE_CMD} -i -e 's,QCoreApplication::applicationDirPath()+"/translations","${DATADIR}/translations",g' \
		${WRKSRC}/settings.cpp

pre-configure:
#Work around badly written .pro
	${LRELEASE} ${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
