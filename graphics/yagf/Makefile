# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yagf
PORTVERSION=	0.9.5
CATEGORIES=	graphics
MASTER_SITES=	SF/yagf-ocr

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Graphical interface for an OCR program (cuneiform and tesseract)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaspell.so:textproc/aspell

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_MULTI=		OCRENGINE
OPTIONS_MULTI_OCRENGINE=CUNEIFORM TESSERACT
CUNEIFORM_DESC=		Cuneiform OCR engine
CUNEIFORM_RUN_DEPENDS=	cuneiform:graphics/cuneiform
TESSERACT_DESC=		Tesseract OCR engine
TESSERACT_RUN_DEPENDS=	tesseract:graphics/tesseract

OPTIONS_DEFAULT=	CUNEIFORM

USES=		cmake desktop-file-utils pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	corelib gui imageformats linguist_build \
		moc_build qmake_build rcc_build uic_build

PLIST_FILES=	bin/yagf lib/yagf/libxspreload.so share/applications/YAGF.desktop\
		share/icons/hicolor/96x96/apps/yagf.png share/pixmaps/yagf.png
PORTDATA=	*

.include <bsd.port.mk>
