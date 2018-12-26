# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	fuel
DISTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	https://fuel-scm.org/files/releases/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	GUI Front-End to the Fossil SCM tool

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	fossil:devel/fossil

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	QT4 QT5
OPTIONS_DEFAULT=	QT5

USES=		gmake qmake shebangfix
QT4_USES=	qt:4
QT4_USE=	QT=corelib,gui,webkit,linguisttools_build,moc_build,rcc_build,uic_build
QT5_USES=	compiler:c++11-lang qt:5
QT5_USE=	QT=core,gui,network,webkit,widgets,buildtools_build,linguisttools_build

SHEBANG_FILES=	intl/convert.sh
PLIST_FILES=	bin/fuel share/applications/fuel.desktop \
		share/icons/hicolor/256x256/apps/fuel.png

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr$$|${PREFIX}|' ${WRKSRC}/fuel.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/rsrc/fuel.desktop

.include <bsd.port.mk>
