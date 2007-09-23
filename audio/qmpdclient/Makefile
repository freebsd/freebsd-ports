# New ports collection makefile for:	qmpdclient
# Date created:		4 June 2007
# Whom:			uyamba@gmail.com
#
# $FreeBSD$
#

PORTNAME=	qmpdclient
PORTVERSION=	1.0.8
CATEGORIES=	audio
MASTER_SITES=	http://havtknut.tihlde.org/qmpdclient/files/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	uyamba@gmail.com
COMMENT=	Easy to use musicpd client written in QT4

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build \
		linguist_build corelib gui
QMAKE_ARGS=	-unix PREFIX=${PREFIX}

OPTIONS=	DBUS	"Enable D-BUS support"	off

DATADIR=	${PREFIX}/share/QMPDClient
PLIST_FILES=	bin/${PORTNAME}
PLIST_DIRS=	${DATADIR_REL}/translations \
		${DATADIR_REL}

USE_DOS2UNIX=	qmpdclient.pro

TRANSLATIONS=	de_DE nl_NL nn_NO no_NO ru_RU
.for lang in ${TRANSLATIONS}
DISTFILES+=	translations/${lang}.ts
PLIST_FILES+=	${DATADIR_REL}/translations/${lang}.qm
.endfor

.include  <bsd.port.pre.mk>

.if defined(WITH_DBUS) && !defined(WITHOUT_DBUS)
QT_COMPONENTS+=	dbus
QMAKE_ARGS+=	CONFIG+=qdbus
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		${QMAKE_ARGS} qmpdclient.pro

post-build:
.for lang in ${TRANSLATIONS}
	@${QT_PREFIX}/bin/lrelease-qt4 -compress \
		${DISTDIR}/${DIST_SUBDIR}/translations/${lang}.ts \
		-qm ${WRKDIR}/${lang}.qm
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${TARGETDIR}/${DATADIR}/translations
.for lang in ${TRANSLATIONS}
	${INSTALL_DATA} ${WRKDIR}/${lang}.qm \
		${TARGETDIR}/${DATADIR}/translations/${lang}.qm
.endfor

.include <bsd.port.post.mk>
