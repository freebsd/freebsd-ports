# Created by: Mina R Waheeb <syncer@gmail.com>
# $FreeBSD$

PORTNAME=	qtscriptgenerator
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	syncer@gmail.com
COMMENT=	Tool that generates Qt bindings for Qt Script

BROKEN_armv6=		fails to build: qtscript_QEasingCurve.cpp:332:32: cannot initialize a parameter of type 'QEasingCurve::EasingFunction' with an lvalue of type 'float'
BROKEN_armv7=		fails to build: qtscript_QEasingCurve.cpp:332:32: cannot initialize a parameter of type 'QEasingCurve::EasingFunction' with an lvalue of type 'float'

USE_GITHUB=	YES
GH_ACCOUNT=	qt-labs
GH_TAGNAME=	a6ce388

OPTIONS_DEFINE=	PHONON
PHONON_DESC=	Build Phonon support
OPTIONS_DEFAULT=	PHONON

USES=		gmake qmake
USE_QT4=	corelib declarative designer doc help help-tools gui \
		iconengines imageformats inputmethods linguist network \
		opengl pixeltool porting qdbusviewer \
		qt3support qtestlib qvfb script scripttools \
		sql svg webkit xml xmlpatterns xmlpatterns-tool \
		moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHONON}
USE_QT4+=	phonon
PLIST_SUB+=	PHONON=""
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-no_phonon
PLIST_SUB+=	PHONON="@comment "
.endif

do-configure:
	@cd ${WRKSRC}/generator && \
		${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS}

do-build:
	@echo "--->  Building generator"
	@cd ${WRKSRC}/generator && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} && \
		${SETENV} ${CONFIGURE_ENV} ./generator \
		--include-paths=${PREFIX}/include/:${PREFIX}/include/qt4/
	@echo "--->  Configuring generated files"
	@cd ${WRKSRC}/qtbindings && \
		${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS} \
		INCLUDEPATH+=${PREFIX}/include/qt4/phonon \
		LIBS+=-L${PREFIX}/lib
	@echo "--->  Building generated files"
	@cd ${WRKSRC}/qtbindings && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/script
	cd ${WRKSRC}/plugins/script && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/${QT_PLUGINDIR_REL}/script

.include <bsd.port.mk>
