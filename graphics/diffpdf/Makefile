# $FreeBSD$

PORTNAME=	diffpdf
PORTVERSION=	2.1.3
PORTREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	http://www.qtrac.eu/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Compare two PDF files-textually or visually

LICENSE=	GPLv2+

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang qmake qt:5 gl
USE_GL=		gl
USE_QT=		buildtools linguist_build core gui printsupport widgets

PLIST_FILES=	bin/diffpdf

pre-configure:
	( cd ${BUILD_WRKSRC} && ${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diffpdf ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
