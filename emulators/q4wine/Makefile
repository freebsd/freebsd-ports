# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	q4wine
DISTVERSION=	1.1-r2
PORTREVISION=	3
CATEGORIES=	emulators deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION:S/.r/-r/}/

MAINTAINER=	koalative@gmail.com
COMMENT=	QT4 front-end for WINE

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	icotool:graphics/icoutils
RUN_DEPENDS=	sudo:security/sudo \
		wget:ftp/wget \
		cabextract:archivers/cabextract \
		icotool:graphics/icoutils

USES=		cmake desktop-file-utils qt:4
CMAKE_ARGS+=	-DMANPAGE_ENTRY_PATH=${MANPREFIX}/man
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT=		qmake_build rcc_build moc_build uic_build \
		linguisttools_build corelib gui sql sql-sqlite3_run network
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS NLS DBUS
OPTIONS_DEFAULT=	DBUS

OPTIONS_SUB=	yes

DBUS_CMAKE_ON=		-DWITH_DBUS:BOOL=ON
DBUS_CMAKE_OFF=		-DWITH_DBUS:BOOL=OFF
DBUS_USES=	qt:4
DBUS_USE=		QT=dbus

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:emulators/wine-devel
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/share/man|/man|' \
		${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} \
		-e 's|^Categories=.*|Categories=Qt;System;Emulator;Utility;Game;|' \
		${WRKSRC}/${PORTNAME}.desktop

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|install(FILES|#install(FILES|' \
		${WRKSRC}/src/i18n/CMakeLists.txt
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
