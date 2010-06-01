# New ports collection makefile for:	kdebindings4-python-pykde4
# Date created:		2009-02-13
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
PKGNAMESUFFIX=	-kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for KDE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtWebKit.so:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_SITELIBDIR}/PyQt4/QtXml.so:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_SITELIBDIR}/PyQt4/phonon.so:${PORTSDIR}/multimedia/py-qt4-phonon
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_SITELIBDIR}/dbus/mainloop/qt.so:${PORTSDIR}/devel/py-qt4-dbus

BINDLANG=	python
BINDMODULE=	pykde4

USE_KDE4=	akonadi kdelibs pimlibs
USE_PYTHON=	2.5+
MAKE_JOBS_SAFE=	yes

SUB_FILES=	kdebindings4.pth
SUB_LIST=	PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR}

EXAMPLESDIR=		${PREFIX}/share/examples/pykde4

.include "${.CURDIR}/../../devel/kdebindings4/files/Makefile.kdebindings"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
BROKEN=		Fails to build with RTLD_NOLOAD
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,$${SIP_DEFAULT_SIP_DIR},${PREFIX}/${SIPDIR_REL},g' \
		-e 's,$${PYTHON_SITE_PACKAGES_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${BUILD_WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e '/ADD_SUBDIRECTORY(examples)/d' \
		-e '/ADD_SUBDIRECTORY(tools)/d' \
		${BUILD_WRKSRC}/CMakeLists.txt
	${RM} ${BUILD_WRKSRC}/examples/CMakeLists.txt

post-configure:
	${REINPLACE_CMD} -e "/INSTALL/s,${PYTHON_SITELIBDIR},${PYTHONPREFIX_SITELIBDIR},g" \
		${BUILD_WRKSRC}/cmake_install.cmake

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${BUILD_WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
	${INSTALL_DATA} ${WRKDIR}/kdebindings4.pth ${PYTHON_SITELIBDIR}

.include <bsd.port.post.mk>
