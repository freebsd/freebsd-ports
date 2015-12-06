# bsd.pyqt.mk - Global definitions for PyQt related ports
#
# $FreeBSD$
#
# Port variables:
# PYQT4_DIST            - This port is part of PyQt4 itself. Variables and
#                         targets are then set assuming a certain tarball and
#                         port layout.
#

PYQT_MAINTAINER=	kde@FreeBSD.org

MASTER_SITE_RIVERBANK=	http://www.riverbankcomputing.com/static/Downloads/%SUBDIR%/

MASTER_SITES_SIP=	SF/pyqt/sip/sip-${PORTVERSION} \
			GENTOO
MASTER_SITES_PYQT4=	SF/pyqt/PyQt4/PyQt-${PORTVERSION} \
			GENTOO
MASTER_SITES_QSCI2=	SF/pyqt/QScintilla2/QScintilla-${PORTVERSION} \
			GENTOO

SIP_VERSION=		4.16.5
PYQT4_VERSION=		4.11.3
QSCI2_VERSION=		2.8.4

SIP_DISTNAME=		sip-${SIP_VERSION}
PYQT4_DISTNAME=		PyQt-x11-gpl-${PYQT4_VERSION}
PYQT4_DISTINFO_FILE=	${.CURDIR}/../../devel/py-qt4/distinfo
QSCI2_DISTNAME=		QScintilla-gpl-${QSCI2_VERSION}
QSCI2_DISTINFO_FILE=	${.CURDIR}/../../devel/qscintilla2/distinfo

PYQT4_COMPONENTS=	assistant core dbus dbussupport declarative \
			demo designer designerplugin doc gui help \
			multimedia network opengl phonon qscintilla2 \
			script scripttools sql svg test webkit xml \
			xmlpatterns

assistant_PORT=		devel/py-qt4-assistant
core_PORT=		devel/py-qt4-core
dbus_PORT=		devel/py-qt4-dbus
dbussupport_PORT=	devel/py-qt4-dbussupport
declarative_PORT=	devel/py-qt4-declarative
demo_PORT=		misc/py-qt4-demo
designer_PORT=		devel/py-qt4-designer
designerplugin_PORT=	devel/py-qt4-designerplugin
doc_PORT=		misc/py-qt4-doc
gui_PORT=		x11-toolkits/py-qt4-gui
help_PORT=		devel/py-qt4-help
multimedia_PORT=	multimedia/py-qt4-multimedia
network_PORT=		net/py-qt4-network
opengl_PORT=		x11/py-qt4-opengl
phonon_PORT=		multimedia/py-qt4-phonon
qscintilla2_PORT=	devel/py-qt4-qscintilla2
script_PORT=		devel/py-qt4-script
scripttools_PORT=	devel/py-qt4-scripttools
sql_PORT=		databases/py-qt4-sql
svg_PORT=		graphics/py-qt4-svg
test_PORT=		devel/py-qt4-test
webkit_PORT=		www/py-qt4-webkit
xml_PORT=		textproc/py-qt4-xml
xmlpatterns_PORT=	textproc/py-qt4-xmlpatterns

assistant_DESC=		Python bindings for QtAssistant module
core_DESC=		Python bindings for QtCore module
dbus_DESC=		Python bindings for QtDBus module
dbussupport_DESC=	Qt event loop support for dbus-python
declarative_DESC=	Python bindings for QtDeclarative module
demo_DESC=		PyQt4 demo and examples
designer_DESC=		Python bindings for QtDesigner module
designerplugin_DESC=	Python bindings for QtDesigner plugin
doc_DESC=		PyQt4 documentation
gui_DESC=		Python bindings for QtGui module
help_DESC=		Python bindings for QtHelp module
multimedia_DESC=	Python bindings for Multimedia module
network_DESC=		Python bindings for QtNetwork module
opengl_DESC=		Python bindings for QtOpenGL module
phonon_DESC=		Python bindings for Phonon module
qscintilla2_DESC=	Python bindings for QScintilla2
script_DESC=		Python bindings for QtScript module
scripttools_DESC=	Python bindings for QtScriptTools module
sql_DESC=		Python bindings for QtSql module
svg_DESC=		Python bindings for QtSvg module
test_DESC=		Python bindings for QtTest module
webkit_DESC=		Python bindings for QtWebKit module
xml_DESC=		Python bindings for QtXml module
xmlpatterns_DESC=	Python bindings for QtXmlPatterns module

.if defined(PYQT4_DIST)
PORTVERSION=	${PYQT4_VERSION}
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USES+=		python

QT_NONSTANDARD=	yes  # Do not add unknown arguments to CONFIGURE_ARGS.

PATCHDIR=	${.CURDIR}/../../devel/py-qt4-core/files
SIPDIR=		${PREFIX}/share/py-sip
QSCIDIR=	${PREFIX}/share/qt4/qsci
CONFIGURE_ARGS+=-b ${PREFIX}/bin \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-q ${QMAKE} \
		--confirm-license \
		--sipdir ${SIPDIR}

# One of the things PyQt4 looks for to determine whether to build the Qt DBus
# main loop module (py-qt4-dbussupport) is whether the dbus/ directory is
# present. Only extract it for that port then.
.if ${PORTNAME} != "dbussupport"
EXTRACT_AFTER_ARGS+=	--exclude "${DISTNAME}/dbus"
.endif  # ${PORTNAME} != "dbussupport"

.if !target(do-configure)
do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}
.endif  # !target(do-configure)
.endif  # defined(PYQT4_DIST)
