# New ports collection makefile for:    qtscriptgenerator
# Date Created:                         13 Apr 2009
# Whom:                                 Mina R Waheeb <syncer@gmail.com>
#
# $FreeBSD$

PORTNAME=	qtscriptgenerator
PORTVERSION=	0.1.0.20101126
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://ns.ael.ru/~fluffy.khv/distfiles/
MASTER_SITE_SUBDIR=	fluffy
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	Qt Script Generator is a tool that generates Qt bindings for Qt Script

OPTIONS=	PHONON	"Build Phonon support" on

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib declarative designer doc help help-tools gui \
		iconengines imageformats inputmethods linguist network \
		opengl pixeltool porting qdbusviewer \
		qt3support qtestlib qvfb script scripttools \
		sql svg webkit xml xmlpatterns xmlpatterns-tool \
		qmake_build moc_build rcc_build uic_build
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_QT_PLUGINS_DIR=	${PREFIX}/lib/qt4/plugins/

.include <bsd.port.options.mk>

.if defined(WITH_PHONON)
QT_COMPONENTS+=	phonon
PLIST_SUB+=	PHONON=""
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-no_phonon
PLIST_SUB+=	PHONON="@comment "
.endif

do-configure:
	@cd ${WRKSRC}/generator/ && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} generator.pro

do-build:
	@echo "--->  Building generator"
	@cd ${WRKSRC}/generator && ${GMAKE} && ${SETENV} ${CONFIGURE_ENV} \
		./generator --include-paths=${PREFIX}/include/:${PREFIX}/include/qt4/
	@echo "--->  Configure generated files"
	@cd ${WRKSRC}/qtbindings && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} INCLUDEPATH+=${PREFIX}/include/qt4/phonon \
		LIBS+=-L${PREFIX}/lib qtbindings.pro
	@echo "--->  Building generated files"
	@cd ${WRKSRC}/qtbindings && ${SETENV} ${MAKE_ENV} && ${GMAKE}

do-install:
	${MKDIR} ${INSTALL_QT_PLUGINS_DIR}/script
	cd ${WRKSRC}/plugins/script/ && ${COPYTREE_SHARE} \* ${INSTALL_QT_PLUGINS_DIR}/script

.include <bsd.port.mk>
