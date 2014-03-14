# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	q4wine
PORTVERSION=	1.1.r2
PORTREVISION=	1
CATEGORIES=	emulators deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION:S/.r/-r/}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}
# http://sourceforge.net/projects/q4wine/files/q4wine/q4wine%201.1-r2/q4wine-1.1-r2.tar.gz/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	QT4 front-end for WINE

LICENSE=	GPLv3

BUILD_DEPENDS=	icotool:${PORTSDIR}/graphics/icoutils
RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo \
		wget:${PORTSDIR}/ftp/wget \
		cabextract:${PORTSDIR}/archivers/cabextract \
		icotool:${PORTSDIR}/graphics/icoutils

USES=		cmake desktop-file-utils
CMAKE_ARGS+=	-DMANPAGE_ENTRY_PATH=${MANPREFIX}/man
USE_GCC=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT4=	qmake_build rcc_build moc_build uic_build \
		linguist_build corelib gui sql network
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS NLS DBUS
OPTIONS_DEFAULT=	DBUS

OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

DBUS_CMAKE_ON=		-DWITH_DBUS:BOOL=ON
DBUS_CMAKE_OFF=		-DWITH_DBUS:BOOL=OFF

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:${PORTSDIR}/emulators/wine-devel
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
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
