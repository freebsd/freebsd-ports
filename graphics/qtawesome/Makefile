# Created by: mi
# $FreeBSD$

PORTNAME=	qtawesome
PORTVERSION=	20150319
PORTREVISION=	1
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
OPTIONS_DEFAULT=	QT5

QT4_USES=	qt:4
QT4_USE=	qt=corelib,gui,qmake_build,moc_build
QT5_USES=	qt:5
QT5_USE=	qt=core,gui,qmake_build,buildtools_build
MAKE_ARGS+=	${PORT_OPTIONS:MQT*:S/QT/QT=/}

WRKSRC_SUBDIR=	QtAwesome
#MAKEFILE=	${FILESDIR}/BSDmakefile
EXTRACT_AFTER_ARGS=--no-same-owner --no-same-permissions	\
		--exclude QtAwesomeSample --exclude fonts
PLIST_FILES=	lib/libQtAwesome.so.1.0.0 lib/libQtAwesome.so.1.0 \
		lib/libQtAwesome.so.1 lib/libQtAwesome.so	\
		include/QtAwesome.h
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-patch:
	${REINPLACE_CMD} -e 's,staticlib,sharedlib,'	\
		-e '/^RESOURCES/,$$d'	\
		${WRKSRC}/QtAwesome.pro

.include <bsd.port.mk>
