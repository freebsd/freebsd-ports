# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	znotes
PORTVERSION=	0.4.5.20150825
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Simple notes managment application based on Qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5
USE_GL=		gl
USE_QT=		buildtools_build linguisttools_build core gui network printsupport widgets xml

USE_GITHUB=	yes
GH_ACCOUNT=	proton
GH_PROJECT=	zNotes
GH_TAGNAME=	6423c5e

CONFLICTS_INSTALL=	znotes-qt[45]

DESKTOP_ENTRIES="zNotes" "Notes managment" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"Utility;TextEditor;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e '/.path =/s|/usr|$$$$PREFIX|g' \
		-e '/PREFIX = /d' \
		${WRKSRC}/${PORTNAME}.pro

pre-configure:
#Work around badly written .pro
	cd ${WRKSRC} && ${LRELEASE} ${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
