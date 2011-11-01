# New ports collection makefile for:	qmpdclient
# Date created:		4 June 2007
# Whom:			uyamba@gmail.com
#
# $FreeBSD$
#

PORTNAME=	qmpdclient
PORTVERSION=	1.2.2
CATEGORIES=	audio
MASTER_SITES=	http://dump.bitcheese.net/files/

MAINTAINER=	uyamba@gmail.com
COMMENT=	Easy to use musicpd client written in Qt4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build \
		corelib gui network xml xmlpatterns
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes
QMAKE_ARGS=	${QMAKE_PRO}
QMAKE_PRO=	${PORTNAME}.pro

OPTIONS=	DBUS	"Enable D-BUS support"	off \
		NLS	"Enable National Language Support" on

DATADIR=	${PREFIX}/share/QMPDClient
WRKSRC=		${WRKDIR}/${PORTNAME}

.include  <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
QT_COMPONENTS+=	linguist_build
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_DBUS) && !defined(WITHOUT_DBUS)
QT_COMPONENTS+=	dbus
QMAKEFLAGS+=	"CONFIG+=qdbus"
.endif

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
QMAKEFLAGS+=	"CONFIG+=debug"
.endif

post-patch:
.if defined(WITHOUT_NLS)
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

.include <bsd.port.post.mk>
