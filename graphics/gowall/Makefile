PORTNAME=	gowall
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Versatile tool to process images
WWW=		https://github.com/Achno/gowall

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libffi.so:devel/libffi \
		libmupdf.so:graphics/mupdf
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		go:modules

GO_MODULE=	github.com/Achno/${PORTNAME}
CGO_LDFLAGS+=	-lmupdf -lffi

# utils/error.go:15:18: non-constant format string in call to ...
TESTING_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFAULT=		PNGQUANT PREVIEW UPSCALE
OPTIONS_GROUP=			COMPRESSION FEATURES OCR
OPTIONS_GROUP_COMPRESSION=	PNGQUANT
OPTIONS_GROUP_FEATURES=		PREVIEW UPSCALE
OPTIONS_GROUP_OCR=		TESSERACT

PNGQUANT_DESC=	Install pngquant PNG image compression method
PREVIEW_DESC=	Install chafa for image previewing support in terminal
TESSERACT_DESC=	Install Tesseract OCR Engine for extracting text from an image or pdf
UPSCALE_DESC=	Install upscaler for upscaling and enhancing images

PNGQUANT_RUN_DEPENDS=	pngquant:graphics/pngquant
PREVIEW_RUN_DEPENDS=	chafa:graphics/chafa
TESSERACT_RUN_DEPENDS=	tesseract:graphics/tesseract
UPSCALE_RUN_DEPENDS=	upscaler:graphics/upscaler

post-patch:
	@${REINPLACE_CMD} -e '23s,([^()]*),("${LOCALBASE}/bin"),g' \
		${WRKSRC}/internal/image/upscale.go

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
EXTRA_PATCHES=	${PATCHDIR}/i386/extra-patch-vendor_github.com_gen2brain_go-fitz_fitz__cgo.go
.endif

.include <bsd.port.mk>
