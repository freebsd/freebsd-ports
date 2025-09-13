PORTNAME=	znotes
DISTVERSION=	0.4.7
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple notes managment application based on Qt
WWW=		http://znotes.sourceforge.net

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Abandonware, depends on legacy QT 5 and last release in 2011
EXPIRATION_DATE=2025-12-31

USES=		compiler:c++11-lang gl qmake qt:5
USE_GL=		gl
USE_QT=		buildtools:build linguisttools:build core gui network \
		printsupport widgets xml

USE_GITHUB=	yes
GH_ACCOUNT=	proton
GH_PROJECT=	zNotes

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
