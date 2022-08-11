PORTNAME=	qtawesome
PORTVERSION=	20150319
PORTREVISION=	4
CATEGORIES=	graphics devel

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Embed Font Awesome glyphs in Qt-applications

LICENSE=	MIT

USE_GITHUB=	yes
USES=		compiler:c++11-lang qmake qt:5
USE_QT=		core gui qmake_build buildtools_build

GH_ACCOUNT=	gamecreature
GH_PROJECT=	QtAwesome
GH_TAGNAME=	d674aef

MAKE_ARGS+=	QT=5

WRKSRC_SUBDIR=	QtAwesome
#MAKEFILE=	${FILESDIR}/BSDmakefile
EXTRACT_AFTER_ARGS=--no-same-owner --no-same-permissions	\
		--exclude QtAwesomeSample --exclude fonts
PLIST_FILES=	lib/libQtAwesome.so.1.0.0 lib/libQtAwesome.so.1.0 \
		lib/libQtAwesome.so.1 lib/libQtAwesome.so	\
		include/QtAwesome.h
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's,staticlib,sharedlib,'	\
		-e '/^RESOURCES/,$$d'	\
		${WRKSRC}/QtAwesome.pro

.include <bsd.port.mk>
