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

BUILD_DEPENDS=	icotool:graphics/icoutils
RUN_DEPENDS=	sudo:security/sudo \
		wget:ftp/wget \
		cabextract:archivers/cabextract \
		icotool:graphics/icoutils

USES=		cmake desktop-file-utils
CMAKE_ARGS+=	-DMANPAGE_ENTRY_PATH=${MANPREFIX}/man
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	qmake_build rcc_build moc_build uic_build \
		linguisttools_build corelib gui sql sql-sqlite3_run network
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS NLS DBUS
OPTIONS_DEFAULT=	DBUS

OPTIONS_SUB=	yes

DBUS_CMAKE_ON=		-DWITH_DBUS:BOOL=ON
DBUS_CMAKE_OFF=		-DWITH_DBUS:BOOL=OFF
DBUS_USE=		QT4=dbus

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
