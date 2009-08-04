#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4

# QT_NONSTANDARD	- Suppress modification of configure and make environment.
# QT_DIST			- Package being built is part of the Qt distribution.

.if !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)
Qt_Include_MAINTAINER=	kde@freebsd.org
Qt_Pre_Include=		bsd.qt.mk

.if !defined(QT_NONSTANDARD)
CONFIGURE_ARGS+=--with-qt-includes=${QT_INCDIR} \
				--with-qt-libraries=${QT_LIBDIR} \
				--with-extra-libs=${LOCALBASE}/lib \
				--with-extra-includes=${LOCALBASE}/include
CONFIGURE_ENV+=	MOC="${MOC}" UIC="${UIC}" CPPFLAGS="${CPPFLAGS} ${QTCPPFLAGS}" LIBS="${QTCFGLIBS}" \
		QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}" QTDIR="${QT_PREFIX}"
MAKE_ENV+=	QMAKESPEC="${QMAKESPEC}"
.endif # !defined(QT_NONSTANDARD)

.if defined(QT_DIST)
#CONFLICTS+=	Currently there are no conflicts \o/

CONFIGURE_ARGS+=-fast -platform ${QMAKESPEC} \
		-L${PREFIX}/${QT_LIBDIR_REL} \
		-qt-gif -system-libjpeg -system-libpng \
		-system-libmng -system-libtiff -system-zlib \
		-opensource -confirm-license \
		-no-pch \
		-prefix ${PREFIX} \
		-bindir ${PREFIX}/bin \
		-libdir ${PREFIX}/${QT_LIBDIR_REL} \
		-docdir ${PREFIX}/share/doc/qt4 \
		-headerdir ${PREFIX}/${QT_INCDIR_REL} \
		-plugindir ${PREFIX}/${QT_PLUGINDIR_REL} \
		-datadir ${PREFIX}/share/qt4 \
		-translationdir ${PREFIX}/share/qt4/translations \
		-sysconfdir ${PREFIX}/etc/xdg \
		-examplesdir ${PREFIX}/share/examples/qt4/examples \
		-demosdir ${PREFIX}/share/examples/qt4/demos

.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=-no-mmx -no-3dnow -no-sse -no-sse2
.endif #defined(PACKAGE_BUILDING)

# .if defined(PORTNAME) && ${PORTNAME} != "xmlpatterns"
# CONFIGURE_ARGS+=-no-exceptions
# .endif

.if defined(WANT_QT_DEBUG)
CONFIGURE_ARGS+=-debug
PLIST_SUB+=	DEBUG=""
.else
CONFIGURE_ARGS+=-release -no-separate-debug-info
PLIST_SUB+=	DEBUG="@comment "
.endif

.if defined(WANT_QT_VERBOSE_CONFIGURE)
CONFIGURE_ARGS+=-verbose
.endif
.endif #defined(QT_DIST)

QT_INCDIR_REL=	include/qt4
QT_LIBDIR_REL=	lib/qt4
QT_PLUGINDIR_REL=	lib/qt4/plugins

PLIST_SUB+=	QT_INCDIR_REL=${QT_INCDIR_REL} \
		QT_LIBDIR_REL=${QT_LIBDIR_REL} \
		QT_PLUGINDIR_REL=${QT_PLUGINDIR_REL}

QT_PREFIX?=	${LOCALBASE}
QT_INCDIR?=	${QT_PREFIX}/${QT_INCDIR_REL}
QT_LIBDIR?=	${QT_PREFIX}/${QT_LIBDIR_REL}
QT_PLUGINDIR?=	${QT_PREFIX}/${QT_PLUGINDIR_REL}
MOC?=		${QT_PREFIX}/bin/moc-qt4
UIC?=		${QT_PREFIX}/bin/uic-qt4
QMAKE?=		${QT_PREFIX}/bin/qmake-qt4
QMAKESPEC?=	${QT_PREFIX}/share/qt4/mkspecs/freebsd-g++
QMAKEFLAGS+=	QMAKE_CC="${CC}" QMAKE_CXX="${CXX}" QMAKE_LINK_SHLIB="${CXX}" \
		QMAKE_LINK="${CXX}" QMAKE_CFLAGS="${CFLAGS}" \
		QMAKE_CXXFLAGS="${CXXFLAGS}" \
		QMAKE_CFLAGS_THREAD="${PTHREAD_CFLAGS}" \
		QMAKE_LFLAGS_THREAD="${PTHREAD_LIBS}"

.if ${OSVERSION} < 700042 && ${ARCH} == "amd64"
QTCPPFLAGS?=	-fno-gcse
.else
QTCPPFLAGS?=
.endif
QTCGFLIBS?=

.endif # !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)

#
# QT4 version
# Don't forget to update ${PORTSDIR}/devel/qt4/files/configure !
#
QT4_VERSION?=		4.5.2

_QT_COMPONENTS_ALL=	accessible assistant assistant-adp assistantclient \
			clucene codecs-cn codecs-jp codecs-kr codecs-tw corelib \
			dbus designer doc help help-tools gui iconengines imageformats \
			inputmethods linguist l10n makeqpf moc network opengl \
			pixeltool porting  phonon phonon-gst qdbusviewer \
			qmake qt3support qtconfig qtestlib qvfb rcc script scripttools \
			sql svg uic uic3 webkit xml xmlpatterns xmlpatterns-tool

accessible_DEPENDS=	accessibility/qt4-accessible
assistant_DEPENDS=	devel/qt4-assistant
assistant-adp_DEPENDS=	devel/qt4-assistant-adp
assistantclient_DEPENDS=devel/qt4-libqtassistantclient
assistantclient_NAME=	libQtAssistantClient
clucene_DEPENDS=	textproc/qt4-clucene
codecs-cn_DEPENDS=	chinese/qt4-codecs-cn
codecs-jp_DEPENDS=	japanese/qt4-codecs-jp
codecs-kr_DEPENDS=	korean/qt4-codecs-kr
codecs-tw_DEPENDS=	chinese/qt4-codecs-tw
corelib_DEPENDS=	devel/qt4-corelib
dbus_DEPENDS=		devel/dbus-qt4
designer_DEPENDS=	devel/qt4-designer
doc_DEPENDS=		misc/qt4-doc
gui_DEPENDS=		x11-toolkits/qt4-gui
help_DEPENDS=		devel/qt4-help
help-tools_DEPENDS=	devel/qt4-help-tools
iconengines_DEPENDS=	graphics/qt4-iconengines
imageformats_DEPENDS=	graphics/qt4-imageformats
inputmethods_DEPENDS=	x11/qt4-inputmethods
linguist_DEPENDS=	devel/qt4-linguist
l10n_DEPENDS=		misc/qt4-l10n
makeqpf_DEPENDS=	devel/qt4-makeqpf
moc_DEPENDS=		devel/qt4-moc
network_DEPENDS=	net/qt4-network
opengl_DEPENDS=		x11/qt4-opengl
pixeltool_DEPENDS=	graphics/qt4-pixeltool
phonon_DEPENDS=		multimedia/qt4-phonon
phonon-gst_DEPENDS=	multimedia/qt4-phonon-gst
porting_DEPENDS=	devel/qt4-porting
qdbusviewer_DEPENDS=	devel/qt4-qdbusviewer
qmake_DEPENDS=		devel/qmake4
qt3support_DEPENDS=	devel/qt4-qt3support
qtconfig_DEPENDS=	misc/qt4-qtconfig
qtestlib_DEPENDS=	devel/qt4-qtestlib
qvfb_DEPENDS=		devel/qt4-qvfb
rcc_DEPENDS=		devel/qt4-rcc
script_DEPENDS=		devel/qt4-script
scripttools_DEPENDS=	devel/qt4-scripttools
sql_DEPENDS=		databases/qt4-sql
svg_DEPENDS=		graphics/qt4-svg
uic_DEPENDS=		devel/qt4-uic
uic3_DEPENDS=		devel/qt4-uic3
webkit_DEPENDS=		www/qt4-webkit
xml_DEPENDS=		textproc/qt4-xml
xmlpatterns_DEPENDS=	textproc/qt4-xmlpatterns
xmlpatterns-tool_DEPENDS=	textproc/qt4-xmlpatterns-tool

.if defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)
Qt_Post_Include= bsd.qt.mk

.for component in ${_QT_COMPONENTS_ALL}
${component}_build_DEPENDS=	${${component}_DEPENDS}
${component}_run_DEPENDS=	${${component}_DEPENDS}
_QT_COMPONENTS_SUFFIXED+=${component} ${component}_build ${component}_run
.endfor

.if defined(QT_COMPONENTS)
.for ext in ${QT_COMPONENTS}
${ext}_QT4_PREFIX?=	qt4-
${ext}_QT4_VERSION?=	${QT4_VERSION}
${ext}_NAME?=		${ext}
_${ext}=		${ext}
.if ${_QT_COMPONENTS_SUFFIXED:M${ext}}!= ""
.if ${_${ext}:M*_build}!= ""
BUILD_DEPENDS+=	${${ext}_QT4_PREFIX}${${ext}_NAME:S/_build//}>=${${ext}_QT4_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
.elif ${_${ext}:M*_run}!= ""
RUN_DEPENDS+=	${${ext}_QT4_PREFIX}${${ext}_NAME:S/_run//}>=${${ext}_QT4_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
.else
BUILD_DEPENDS+=	${${ext}_QT4_PREFIX}${${ext}_NAME}>=${${ext}_QT4_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
RUN_DEPENDS+=	${${ext}_QT4_PREFIX}${${ext}_NAME}>=${${ext}_QT4_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
.endif
.else
IGNORE= cannot install: unknown Qt4 component -- ${ext}
.endif
.endfor
.endif

.endif
