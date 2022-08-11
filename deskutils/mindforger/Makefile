PORTNAME=	mindforger
PORTVERSION=	1.54.0
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Thinking notebook and markdown editor

LICENSE=	GPLv2+

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		pkgconfig qmake qt:5
USE_QT=		buildtools_build core declarative gui location network \
		printsupport webchannel widgets
USE_GITHUB=	yes
GH_ACCOUNT=	dvorka
GH_PROJECT=	cmark:cm
GH_TAGNAME=	4ca8688:cm
GH_SUBDIR=	deps/cmark-gfm:cm

QMAKE_ARGS=	CONFIG+="mfnocxx"

OPTIONS_DEFINE=	CMARK
OPTIONS_DEFAULT=	CMARK
CMARK_DESC=	CommonMark support (Markdown -> HTML rendering)

CMARK_BUILD_DEPENDS=	cmake:devel/cmake
CMARK_QMAKE_OFF=	CONFIG+="mfnomd2html"

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
USE_QT+=	webengine
QMAKE_ARGS+=	CONFIG+="mfwebengine"
.else
USE_QT+=	webkit
.endif

pre-build-CMARK-on:
	@cd ${WRKSRC_cm} && cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
		-DCMARK_TESTS:BOOL=OFF -DCMARK_SHARED:BOOL=OFF \
		-B build && cmake --build build

post-patch:
	@${REINPLACE_CMD} -e '/_WIN32/s,_APPLE,_${OPSYS},' \
		${WRKSRC}/app/src/qt/note_view_presenter.cpp \
		${WRKSRC}/app/src/qt/note_view_presenter.h \
		${WRKSRC}/app/src/qt/outline_header_view_presenter.cpp
	@${REINPLACE_CMD} -e 's/53/54/' ${WRKSRC}/lib/src/app_info.h
	@${REINPLACE_CMD} -e 's/_current_dir_name(/cwd(nullptr, 0/' \
		${WRKSRC}/lib/src/gear/file_utils.cpp

.include <bsd.port.mk>
