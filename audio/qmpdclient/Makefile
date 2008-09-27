# New ports collection makefile for:	qmpdclient
# Date created:		4 June 2007
# Whom:			uyamba@gmail.com
#
# $FreeBSD$
#

PORTNAME=	qmpdclient
PORTVERSION=	1.0.9
CATEGORIES=	audio
MASTER_SITES=	http://havtknut.tihlde.org/qmpdclient/files/%SUBDIR%/:src,i18n
MASTER_SITE_SUBDIR=	translations/:i18n
DISTFILES=	${EXTRACT_ONLY}:src ${I18N_DISTFILES}
DIST_SUBDIR=	${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	uyamba@gmail.com
COMMENT=	Easy to use musicpd client written in QT4

HAS_CONFIGURE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build \
		corelib xml gui
QMAKE_ARGS=	-unix PREFIX=${PREFIX}

OPTIONS=	DBUS	"Enable D-BUS support"	off

DATADIR=	${PREFIX}/share/QMPDClient
PLIST_FILES=	bin/${PORTNAME}

USE_DOS2UNIX=	qmpdclient.pro

.include  <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build

TRANSLATIONS=	de_DE fr_FR it_IT nl_NL nn_NO no_NO ru_RU \
		sv_SE tr_TR zh_CN zh_TW

.for lang in ${TRANSLATIONS}
I18N_DISTFILES+=${lang}.ts:i18n
PLIST_FILES+=	${DATADIR_REL}/translations/${lang}.qm
.endfor
PLIST_DIRS=	${DATADIR_REL}/translations \
		${DATADIR_REL}
.endif

.if defined(WITH_DBUS) && !defined(WITHOUT_DBUS)
QT_COMPONENTS+=	dbus
QMAKE_ARGS+=	CONFIG+=qdbus
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		${QMAKE_ARGS} qmpdclient.pro

post-build:
.if !defined(WITHOUT_NLS)
.for lang in ${TRANSLATIONS}
	@${QT_PREFIX}/bin/lrelease-qt4 -compress \
		${DISTDIR}/${DIST_SUBDIR}/${lang}.ts \
		-qm ${WRKDIR}/${lang}.qm
.endfor
.else
	@${DO_NADA}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(WITHOUT_NLS)
	${MKDIR} ${DATADIR}/translations
.for lang in ${TRANSLATIONS}
	${INSTALL_DATA} ${WRKDIR}/${lang}.qm \
		${DATADIR}/translations/${lang}.qm
.endfor
.endif

.include <bsd.port.post.mk>
