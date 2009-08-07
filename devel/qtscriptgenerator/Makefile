# New ports collection makefile for:    qtscriptgenerator
# Date Created:                         13 Apr 2009
# Whom:                                 Mina R Waheeb <syncer@gmail.com>
#
# $FreeBSD$

PORTNAME=	qtscriptgenerator
PORTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	Qt Script Generator is a tool that generates Qt bindings for Qt Script

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib designer doc help help-tools gui iconengines \
		imageformats inputmethods linguist network opengl \
		phonon pixeltool porting qdbusviewer \
		qt3support qtestlib qvfb script scripttools \
		sql svg webkit xml xmlpatterns xmlpatterns-tool \
		qmake_build moc_build rcc_build uic_build
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_QT_PLUGINS_DIR=	${PREFIX}/lib/qt4/plugins/

do-configure:
	@cd ${WRKSRC}/generator/ && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} generator.pro

do-build:
	@echo "--->  Building generator"
	@cd ${WRKSRC}/generator && ${GMAKE} && ${SETENV} ${CONFIGURE_ENV} \
		./generator --include-paths=${PREFIX}/include/:${PREFIX}/include/qt4/
	@echo "--->  Building generated files"
	@cd ${WRKSRC}/qtbindings && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} INCLUDEPATH+=${PREFIX}/include/qt4/phonon \
		LIBS+=-L${PREFIX}/lib qtbindings.pro && ${GMAKE}

do-install:
	${MKDIR} ${INSTALL_QT_PLUGINS_DIR}/script
	cd ${WRKSRC}/plugins/script/ && ${COPYTREE_SHARE} \* ${INSTALL_QT_PLUGINS_DIR}/script

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

.include <bsd.port.post.mk>
