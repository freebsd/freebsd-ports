# $FreeBSD$

PORTNAME=	pykde4
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde python
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for KDE

LIB_DEPENDS=	libqwt.so:x11-toolkits/qwt5
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtDesigner.so:devel/py-qt4-designer \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:net/py-qt4-network \
		${PYTHON_SITELIBDIR}/PyQt4/QtOpenGL.so:x11/py-qt4-opengl \
		${PYTHON_SITELIBDIR}/PyQt4/QtSql.so:databases/py-qt4-sql \
		${PYTHON_SITELIBDIR}/PyQt4/QtXml.so:textproc/py-qt4-xml \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtWebKit.so:www/py-qt4-webkit \
		${PYTHON_SITELIBDIR}/PyQt4/phonon.so:multimedia/py-qt4-phonon \
		${PYTHON_SITELIBDIR}/PyQt4/QtDeclarative.so:devel/py-qt4-declarative
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:devel/py-qt4-dbussupport

USE_KDE4=	kdelibs kdeprefix nepomuk-core okular pimlibs \
		akonadi automoc4 soprano
USE_QT4=	corelib dbus designer_build gui network xml \
		qmake_build moc_build uic_build rcc_build
USES=		cmake:outsource python:2 tar:xz
CMAKE_ARGS+=	-DWITH_PolkitQt:BOOL=FALSE

SUB_FILES=	kdebindings4.pth
SUB_LIST=	PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR}

PLIST_SUB+=	SIPDIR=share/sip

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${FIND} -d ${PATCH_WRKSRC}/sip -name "*.orig" -delete

pre-configure:
	${REINPLACE_CMD} -e '/add_subdirectory(examples)/ d' \
		-e '/add_subdirectory(tools)/ d' \
		${WRKSRC}/CMakeLists.txt
	${RM} ${WRKSRC}/examples/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKDIR}/kdebindings4.pth ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
