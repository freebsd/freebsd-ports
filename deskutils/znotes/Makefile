PORTNAME=	znotes
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
CATEGORIES=	deskutils

MAINTAINER=	daeron767@gmail.com
COMMENT=	Lightweight cross-platform note-taking application (Qt 6 port)
WWW=		https://github.com/daeron767/zNotes/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	daeron767
GH_PROJECT=	zNotes
USE_GL=		opengl
USE_QT=		base tools:build

post-patch:
	@${REINPLACE_CMD} -e 's|isEmpty(PREFIX):PREFIX = /usr|PREFIX = ${PREFIX}|g' \
		-e 's|/usr/share/|$$\$$PREFIX/share/|g' \
		-e 's|pixmap.files = \*\.png|pixmap.files = znotes.png|g' \
		${WRKSRC}/znotes.pro

pre-configure:
#Work around badly written .pro
	cd ${WRKSRC} && ${LRELEASE} ${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
