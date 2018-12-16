# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	znotes
PORTVERSION=	0.4.5.20150825
PORTREVISION=	1
CATEGORIES=	deskutils
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Simple notes managment application based on Qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

USES=		qmake
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	proton
GH_PROJECT=	zNotes
GH_TAGNAME=	6423c5e

. if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		qt:4
USE_QT=		uic_build moc_build rcc_build linguisttools_build corelib gui network xml
. else
USES+=		qt:5
USE_QT=		buildtools_build linguisttools_build core gui network printsupport widgets xml
. endif

DESKTOP_ENTRIES="zNotes" "Notes managment" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"Utility;TextEditor;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e '/.path =/s|/usr|$$$$PREFIX|g' \
		-e '/PREFIX = /d' \
		${WRKSRC}/${PORTNAME}.pro

pre-configure:
#Work around badly written .pro
	${LRELEASE} ${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
