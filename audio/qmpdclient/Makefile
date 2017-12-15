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

USES=		qmake tar:bzip2
USE_QT4=	moc_build rcc_build uic_build \
		corelib gui network xml xmlpatterns
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DBUS NLS DEBUG

DATADIR=	${PREFIX}/share/QMPDClient
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_SUB=	yes

NLS_USE=	QT4=linguisttools_build

DBUS_QMAKE_ON=	CONFIG+=qdbus
DBUS_USE=	QT4=dbus

DEBUG_QMAKE_ON=	CONFIG+=debug

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/${PORTNAME}.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/src/notifications_dbus.cpp

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/INSTALLS += translations/d' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
