# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	mindforger
PORTVERSION=	1.52.0
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Thinking notebook and markdown editor

LICENSE=	GPLv2+

USES=		qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	dvorka
USE_QT=		buildtools_build core declarative gui location network \
		printsupport webchannel webengine widgets

QMAKE_ARGS=	CONFIG+="mfwebengine mfnocxx mfnomd2html"

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
