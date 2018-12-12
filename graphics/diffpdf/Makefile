# $FreeBSD$

PORTNAME=	diffpdf
PORTVERSION=	2.1.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.qtrac.eu/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Compare two PDF files-textually or visually

LICENSE=	GPLv2+

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4

USES=		compiler:c++11-lang qmake qt:4
USE_QT=		qmake_build moc_build rcc_build uic_build linguist_build

PLIST_FILES=	bin/diffpdf

pre-configure:
	${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diffpdf ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
