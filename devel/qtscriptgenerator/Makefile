# New ports collection makefile for:    qtscriptgenerator
# Date Created:                         13 Apr 2009
# Whom:                                 Mina R Waheeb <syncer@gmail.com>
#
# $FreeBSD$

PORTNAME=	qtscriptgenerator
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	Tool that generates Qt bindings for Qt Script

OPTIONS=	PHONON	"Build Phonon support" on

USE_QT_VER=	4
QT_COMPONENTS=	corelib declarative designer doc help help-tools gui \
		iconengines imageformats inputmethods linguist network \
		opengl pixeltool porting qdbusviewer \
		qt3support qtestlib qvfb script scripttools \
		sql svg webkit xml xmlpatterns xmlpatterns-tool \
		qmake_build moc_build rcc_build uic_build
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PHONON)
QT_COMPONENTS+=	phonon
PLIST_SUB+=	PHONON=""
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-no_phonon
PLIST_SUB+=	PHONON="@comment "
.endif

do-configure:
	@cd ${WRKSRC}/generator && \
		${SETENV} ${CONFIGURE_ENV} ${QMAKE} \
		PREFIX=${PREFIX} \
		generator.pro

do-build:
	@echo "--->  Building generator"
	@cd ${WRKSRC}/generator && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} && \
		${SETENV} ${CONFIGURE_ENV} ./generator \
		--include-paths=${PREFIX}/include/:${PREFIX}/include/qt4/
	@echo "--->  Configuring generated files"
	@cd ${WRKSRC}/qtbindings && \
		${SETENV} ${CONFIGURE_ENV} ${QMAKE} \
		PREFIX=${PREFIX} \
		INCLUDEPATH+=${PREFIX}/include/qt4/phonon \
		LIBS+=-L${PREFIX}/lib \
		qtbindings.pro
	@echo "--->  Building generated files"
	@cd ${WRKSRC}/qtbindings && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS}

do-install:
	${MKDIR} ${PREFIX}/${QT_PLUGINDIR_REL}/script
	cd ${WRKSRC}/plugins/script && \
		${COPYTREE_SHARE} \* ${PREFIX}/${QT_PLUGINDIR_REL}/script

.include <bsd.port.mk>
