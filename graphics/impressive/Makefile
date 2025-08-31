PORTNAME=	impressive
DISTVERSION=	0.13.2
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	SF/${PORTNAME}/Impressive/${DISTVERSION}/
DISTNAME=	Impressive-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Stylish way of giving presentations
WWW=		https://impressive.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR}

USES=		python sdl shebangfix
USE_SDL=	sdl

SHEBANG_FILES=	impressive.py
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

PORTDOCS=	${PORTNAME}.html demo.pdf

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	MULTIMEDIA PDFFEATURE
OPTIONS_MULTI=	PDFENGINE
OPTIONS_DEFAULT=FFMPEG MPLAYER MUPDF PDFTK XDG

OPTIONS_GROUP_MULTIMEDIA=	FFMPEG MPLAYER
OPTIONS_GROUP_PDFFEATURE=	PDFTK XDG
OPTIONS_MULTI_PDFENGINE=	GHOSTSCRIPT MUPDF POPPLER XPDF

FFMPEG_DESC=		Optimize generation of video preview images
MPLAYER_DESC=		Enable audio/video playback
PDFTK_DESC=		Enable automatic extraction of PDF page titles
XDG_DESC=		Enable web/e-mail hyperlinks in PDF files
GHOSTSCRIPT_DESC=	Use Ghostscript for PDF rendering
MUPDF_DESC=		Use MuPDF for PDF rendering
POPPLER_DESC=		Use Poppler for PDF rendering
XPDF_DESC=		Use Xpdf for PDF rendering

FFMPEG_IMPLIES=		MPLAYER
GHOSTSCRIPT_IMPLIES=	PDFTK
POPPLER_IMPLIES=	PDFTK
XPDF_IMPLIES=		PDFTK

FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
PDFTK_RUN_DEPENDS=	pdftk:print/pdftk
XDG_RUN_DEPENDS=	xdg-open:devel/xdg-utils
GHOSTSCRIPT_USES=	ghostscript:run
MUPDF_RUN_DEPENDS=	mupdf:graphics/mupdf
POPPLER_RUN_DEPENDS=	pdftoppm:graphics/poppler-utils
XPDF_RUN_DEPENDS=	${LOCALBASE}/libexec/xpdf/pdftoppm:graphics/xpdf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
