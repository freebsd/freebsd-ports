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

CONFIGURE_ARGS+=-fast ${CUPS} -platform ${QMAKESPEC} \
		-L${PREFIX}/${QT_LIBDIR_REL} \
		-qt-gif -system-libjpeg -system-libpng \
		-system-libmng -system-libtiff -system-zlib \
		-confirm-license \
		-prefix ${PREFIX} \
		-bindir ${PREFIX}/bin \
		-libdir ${PREFIX}/${QT_LIBDIR_REL} \
		-docdir ${PREFIX}/share/doc/qt4 \
		-headerdir ${PREFIX}/${QT_INCDIR_REL} \
		-plugindir ${PREFIX}/lib/qt4/plugins \
		-datadir ${PREFIX}/share/qt4 \
		-translationdir ${PREFIX}/share/qt4/translations \
		-sysconfdir ${PREFIX}/etc/xdg \
		-examplesdir ${PREFIX}/share/examples/qt4/examples \
		-demosdir ${PREFIX}/share/examples/qt4/demos

.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=-no-mmx -no-3dnow -no-sse -no-sse2
.endif #defined(PACKAGE_BUILDING)

.if defined(PORTNAME) && ${PORTNAME} != "xmlpatterns"
CONFIGURE_ARGS+=-no-exceptions
.endif

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

QT_PREFIX?=	${LOCALBASE}
QT_INCDIR?=	${QT_PREFIX}/${QT_INCDIR_REL}
QT_LIBDIR?=	${QT_PREFIX}/${QT_LIBDIR_REL}
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
QT4_VERSION?=		4.4.1

_QT_COMPONENTS_ALL=	accessible assistant assistant-adp assistantclient \
			clucene codecs-cn codecs-jp codecs-kr codecs-tw corelib \
			dbus designer doc help help-tools gui iconengines imageformats \
			inputmethods linguist makeqpf moc network opengl \
			pixeltool porting  phonon phonon-gst qdbusviewer \
			qmake qt3support qtconfig qtestlib qvfb rcc script \
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
sql_DEPENDS=		databases/qt4-sql
svg_DEPENDS=		graphics/qt4-svg
uic_DEPENDS=		devel/qt4-uic
uic3_DEPENDS=		devel/qt4-uic3
webkit_DEPENDS=		www/qt4-webkit
xml_DEPENDS=		textproc/qt4-xml
xmlpatterns_DEPENDS=	textproc/qt4-xmlpatterns
xmlpatterns-tool_DEPENDS=	textproc/qt4-xmlpatterns-tool

accessible_build_DEPENDS=	${accessible_DEPENDS}
assistant_build_DEPENDS=	${assistant_DEPENDS}
assistant-adp_build_DEPENDS=	${assistant-adp_DEPENDS}
assistantclient_build_DEPENDS=	${assistantclient_DEPENDS}
assistantclient_build_NAME=	${assistantclient_NAME}
clucene_build_DEPENDS=		${clucene_DEPENDS}
codecs-cn_build_DEPENDS=	${codecs-cn_DEPENDS}
codecs-jp_build_DEPENDS=	${codecs-jp_DEPENDS}
codecs-kr_build_DEPENDS=	${codecs-kr_DEPENDS}
codecs-tw_build_DEPENDS=	${codecs-tw_DEPENDS}
corelib_build_DEPENDS=		${corelib_DEPENDS}
dbus_build_DEPENDS=		${dbus_DEPENDS}
designer_build_DEPENDS=		${designer_DEPENDS}
doc_build_DEPENDS=		${doc_DEPENDS}
gui_build_DEPENDS=		${gui_DEPENDS}
help_build_DEPENDS=		${help_DEPENDS}
help-tools_build_DEPENDS=	${help-tools_DEPENDS}
iconengines_build_DEPENDS=	${iconengines_DEPENDS}
imageformats_build_DEPENDS=	${imageformats_DEPENDS}
inputmethods_build_DEPENDS=	${inputmethods_DEPENDS}
linguist_build_DEPENDS=		${linguist_DEPENDS}
makeqpf_build_DEPENDS=		${makeqpf_DEPENDS}
moc_build_DEPENDS=		${moc_DEPENDS}
network_build_DEPENDS=		${network_DEPENDS}
opengl_build_DEPENDS=		${opengl_DEPENDS}
pixeltool_build_DEPENDS=	${pixeltool_DEPENDS}
phonon_build_DEPENDS=		${phonon_DEPENDS}
phonon-gst_build_DEPENDS=	${phonon-gst_DEPENDS}
porting_build_DEPENDS=		${porting_DEPENDS}
qdbusviewer_build_DEPENDS=	${qdbusviewer_DEPENDS}
qmake_build_DEPENDS=		${qmake_DEPENDS}
qt3support_build_DEPENDS=	${qt3support_DEPENDS}
qtconfig_build_DEPENDS=		${qtconfig_DEPENDS}
qtestlib_build_DEPENDS=		${qtestlib_DEPENDS}
qvfb_build_DEPENDS=		${qvfb_DEPENDS}
rcc_build_DEPENDS=		${rcc_DEPENDS}
script_build_DEPENDS=		${script_DEPENDS}
sql_build_DEPENDS=		${sql_DEPENDS}
svg_build_DEPENDS=		${svg_DEPENDS}
uic_build_DEPENDS=		${uic_DEPENDS}
uic3_build_DEPENDS=		${uic3_DEPENDS}
webkit_build_DEPENDS=		${webkit_DEPENDS}
xml_build_DEPENDS=		${xml_DEPENDS}
xmlpatterns_build_DEPENDS=	${xmlpatterns_DEPENDS}
xmlpatterns-tool_build_DEPENDS=	${xmlpatterns-tool_DEPENDS}

accessible_run_DEPENDS=		${accessible_DEPENDS}
assistant_run_DEPENDS=		${assistant_DEPENDS}
assistant-adp_run_DEPENDS=	${assistant-adp_DEPENDS}
assistantclient_run_DEPENDS=	${assistantclient_DEPENDS}
assistantclient_run_NAME=	${assistantclient_NAME}
clucene_run_DEPENDS=		${clucene_DEPENDS}
codecs-cn_run_DEPENDS=		${codecs-cn_DEPENDS}
codecs-jp_run_DEPENDS=		${codecs-jp_DEPENDS}
codecs-kr_run_DEPENDS=		${codecs-kr_DEPENDS}
codecs-tw_run_DEPENDS=		${codecs-tw_DEPENDS}
corelib_run_DEPENDS=		${corelib_DEPENDS}
dbus_run_DEPENDS=		${dbus_DEPENDS}
designer_run_DEPENDS=		${designer_DEPENDS}
doc_run_DEPENDS=		${doc_DEPENDS}
gui_run_DEPENDS=		${gui_DEPENDS}
help_run_DEPENDS=		${help_DEPENDS}
help-tools_run_DEPENDS=		${help-tools_DEPENDS}
iconengines_run_DEPENDS=	${iconengines_DEPENDS}
imageformats_run_DEPENDS=	${imageformats_DEPENDS}
inputmethods_run_DEPENDS=	${inputmethods_DEPENDS}
linguist_run_DEPENDS=		${linguist_DEPENDS}
makeqpf_run_DEPENDS=		${makeqpf_DEPENDS}
moc_run_DEPENDS=		${moc_DEPENDS}
network_run_DEPENDS=		${network_DEPENDS}
opengl_run_DEPENDS=		${opengl_DEPENDS}
pixeltool_run_DEPENDS=		${pixeltool_DEPENDS}
phonon_run_DEPENDS=		${phonon_DEPENDS}
phonon-gst_run_DEPENDS=		${phonon-gst_DEPENDS}
porting_run_DEPENDS=		${porting_DEPENDS}
qdbusviewer_run_DEPENDS=	${qdbusviewer_DEPENDS}
qmake_run_DEPENDS=		${qmake_DEPENDS}
qt3support_run_DEPENDS=		${qt3support_DEPENDS}
qtconfig_run_DEPENDS=		${qtconfig_DEPENDS}
qtestlib_run_DEPENDS=		${qtestlib_DEPENDS}
qvfb_run_DEPENDS=		${qvfb_DEPENDS}
rcc_run_DEPENDS=		${rcc_DEPENDS}
script_run_DEPENDS=		${script_DEPENDS}
sql_run_DEPENDS=		${sql_DEPENDS}
svg_run_DEPENDS=		${svg_DEPENDS}
uic_run_DEPENDS=		${uic_DEPENDS}
uic3_run_DEPENDS=		${uic3_DEPENDS}
webkit_run_DEPENDS=		${webkit_DEPENDS}
xml_run_DEPENDS=		${xml_DEPENDS}
xmlpatterns_run_DEPENDS=	${xmlpatterns_DEPENDS}
xmlpatterns-tool_run_DEPENDS=	${xmlpatterns-tool_DEPENDS}

.if defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)
Qt_Post_Include= bsd.qt.mk

.for component in ${_QT_COMPONENTS_ALL}
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
.else
BUILD_DEPENDS+=		qt4>=${QT4_VERSION}:${PORTSDIR}/devel/qt4
RUN_DEPENDS+=		qt4>=${QT4_VERSION}:${PORTSDIR}/devel/qt4
.endif

.endif
