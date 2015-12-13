# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yagf
PORTVERSION=	0.9.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://symmetrica.net/cuneiform-linux/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Graphical interface for an OCR program (cuneiform and tesseract)

BROKEN=		unfetchable
LICENSE=	GPLv3

LIB_DEPENDS=	libaspell.so:${PORTSDIR}/textproc/aspell

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_MULTI=		OCRENGINE
OPTIONS_MULTI_OCRENGINE=CUNEIFORM TESSERACT
CUNEIFORM_DESC=		Cuneiform OCR engine
TESSERACT_DESC=		Tesseract OCR engine

OPTIONS_DEFAULT=	CUNEIFORM

USES=		cmake desktop-file-utils pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	corelib gui imageformats linguist_build \
		moc_build qmake_build rcc_build uic_build

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/yagf lib/yagf/libxspreload.so share/applications/YAGF.desktop\
		share/icons/hicolor/96x96/apps/yagf.png share/pixmaps/yagf.png
PORTDATA=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUNEIFORM}
RUN_DEPENDS+=	cuneiform:${PORTSDIR}/graphics/cuneiform
.endif
.if ${PORT_OPTIONS:MTESSERACT}
RUN_DEPENDS+=	tesseract:${PORTSDIR}/graphics/tesseract
.endif

.include <bsd.port.mk>
