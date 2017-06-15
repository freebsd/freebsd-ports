# Created by: mi
# $FreeBSD$

PORTNAME=	qtawesome
PORTVERSION=	20150319
CATEGORIES=	graphics devel

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Embed Font Awesome glyphs in Qt-applications

LICENSE=	MIT

USE_GITHUB=	yes
USES=		qmake

GH_ACCOUNT=	gamecreature
GH_PROJECT=	QtAwesome
GH_TAGNAME=	d674aef

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	QT4 QT5
OPTIONS_DEFAULT=	QT4

QT4_USE=	qt4=corelib,gui,qmake_build,moc_build
QT5_USE=	qt5=core,gui,qmake_build,buildtools_build
MAKE_ARGS+=	${PORT_OPTIONS:MQT*:S/QT/QT=/}

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
