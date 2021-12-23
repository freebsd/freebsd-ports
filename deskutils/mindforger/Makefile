# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	mindforger
PORTVERSION=	1.52.0
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Thinking notebook and markdown editor

LICENSE=	GPLv2+

USES=		qmake qt:5
USE_QT=		buildtools_build core declarative gui location network \
		printsupport webchannel webengine widgets
USE_GITHUB=	yes
GH_ACCOUNT=	dvorka
GH_PROJECT=	cmark:cm
GH_TAGNAME=	f06d944:cm
GH_SUBDIR=	deps/cmark-gfm:cm

QMAKE_ARGS=	CONFIG+="mfnocxx mfwebengine"

OPTIONS_DEFINE=	CMARK
OPTIONS_DEFAULT=	CMARK
CMARK_DESC=	CommonMark support (Markdown -> HTML rendering)

CMARK_BUILD_DEPENDS=	cmake:devel/cmake
CMARK_QMAKE_OFF=	CONFIG+="mfnomd2html"

pre-build-CMARK-on:
	@cd ${WRKSRC_cm} && cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
		-DCMARK_TESTS:BOOL=OFF -DCMARK_SHARED:BOOL=OFF \
		-B build && cmake --build build

post-patch:
	@${REINPLACE_CMD} -e '/_WIN32/s,_APPLE,_${OPSYS},' \
		${WRKSRC}/app/src/qt/note_view_presenter.cpp \
		${WRKSRC}/app/src/qt/note_view_presenter.h \
		${WRKSRC}/app/src/qt/outline_header_view_presenter.cpp
	@${REINPLACE_CMD} -e '/#include <sys\/dir\.h>/d' \
		${WRKSRC}/lib/src/config/config.h
	@${REINPLACE_CMD} -e '/path = /s,/usr,$$$$PREFIX,' \
		${WRKSRC}/app/app.pro ${WRKSRC}/mindforger.pro

.include <bsd.port.mk>
