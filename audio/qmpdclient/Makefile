# Created by: uyamba@gmail.com
# $FreeBSD$

PORTNAME=	qmpdclient
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://dump.bitcheese.net/files/

MAINTAINER=	uyamba@gmail.com
COMMENT=	Easy to use musicpd client written in Qt4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build \
		corelib gui network xml xmlpatterns
INSTALLS_ICONS=	yes
QMAKE_ARGS=	${QMAKE_PRO}
QMAKE_PRO=	${PORTNAME}.pro

OPTIONS_DEFINE=	DBUS NLS DEBUG

DATADIR=	${PREFIX}/share/QMPDClient
WRKSRC=		${WRKDIR}/${PORTNAME}

.include  <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS="@comment "
.else
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
QMAKEFLAGS+=	"CONFIG+=qdbus"
.endif

.if ${PORT_OPTIONS:MDEBUG}
QMAKEFLAGS+=	"CONFIG+=debug"
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/INSTALLS += translations/d' \
		${WRKSRC}/${QMAKE_PRO}
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		-e 's|lupdate|lupdate-qt4|' \
		-e 's|lrelease|lrelease-qt4|' \
		${WRKSRC}/${QMAKE_PRO}
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/src/notifications_dbus.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} \
		${QMAKEFLAGS} ${QMAKE_ARGS}

.include <bsd.port.mk>
