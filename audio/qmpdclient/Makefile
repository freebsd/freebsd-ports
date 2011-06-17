# New ports collection makefile for:	qmpdclient
# Date created:		4 June 2007
# Whom:			uyamba@gmail.com
#
# $FreeBSD$
#

PORTNAME=	qmpdclient
PORTVERSION=	1.2.1
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
		corelib gui network webkit xml xmlpatterns
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes
QMAKE_ARGS=	${QMAKE_PRO}
QMAKE_PRO=	${PORTNAME}.pro

OPTIONS=	DBUS	"Enable D-BUS support"	off

DATADIR=	${PREFIX}/share/QMPDClient
WRKSRC=		${WRKDIR}/${PORTNAME}

.include  <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build
.endif

# TRANSLATIONS=	cs_CZ de_DE es_ES fr_FR it_IT nl_NL nn_NO no_NO \
# 		pt_BR ru_RU sv_SE tr_TR uk_UA zh_CN zh_TW

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
