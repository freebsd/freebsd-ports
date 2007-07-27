.if !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)
Qt_Include_MAINTAINER=	kde@freebsd.org
Qt_Pre_Include=		bsd.qt.mk

.if !defined(QT_NONSTANDARD)
CONFIGURE_ARGS+=--with-qt-includes=${QT_PREFIX}/include \
				--with-qt-libraries=${QT_PREFIX}/lib \
				--with-extra-libs=${LOCALBASE}/lib \
				--with-extra-includes=${LOCALBASE}/include
CONFIGURE_ENV+=	MOC="${MOC}" UIC="${UIC}" CPPFLAGS="${CPPFLAGS} ${QTCPPFLAGS}" LIBS="${QTCFGLIBS}" \
		QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}" QTDIR="${QT_PREFIX}"
MAKE_ENV+=	QMAKESPEC="${QMAKESPEC}"
.endif # !defined(QT_NONSTANDARD)

.if defined(QT_DIST)
#CONFLICTS+=	Currently there are no conflicts \o/
CONFIGURE_ARGS+=-fast -no-exceptions ${CUPS} \
		-platform ${LOCALBASE}/share/qt4/mkspecs/freebsd-g++ \
		-qt-gif -release -system-libjpeg -system-libpng \
		-system-libmng -system-libtiff -system-zlib \
		-confirm-license \
                -prefix ${PREFIX} \
                -docdir ${PREFIX}/share/doc/qt4 \
                -headerdir ${PREFIX}/include \
                -plugindir ${PREFIX}/lib/plugins \
                -datadir ${PREFIX}/share/qt4 \
                -libdir ${PREFIX}/lib \
                -translationdir ${PREFIX}/share/qt4/translations \
                -sysconfdir ${PREFIX}/local/etc/xdg \
                -examplesdir ${PREFIX}/share/qt4/examples \
                -demosdir ${PREFIX}/share/qt4/demos \
                -bindir ${PREFIX}/bin
.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=-no-3dnow -no-sse -no-sse2
.endif #defined(PACKAGE_BUILDING)

.if defined(QT_WANT_VERBOSE_CONFIGURE)
CONFIGURE_ARGS+=-v
.endif
.endif #defined(QT_DIST)

QT_PREFIX?=	${LOCALBASE}
MOC?=		${QT_PREFIX}/bin/moc-qt4
UIC?=		${QT_PREFIX}/bin/uic-qt4
QMAKE?=		${QT_PREFIX}/bin/qmake-qt4
QMAKESPEC?=	${QT_PREFIX}/share/qt4/mkspecs/freebsd-g++

.if ${OSVERSION} < 700042 && ${ARCH} == "amd64"
QTCPPFLAGS?=	-fno-gcse
.else
QTCPPFLAGS?=
.endif
QTCGFLIBS?=

.endif # !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)

QT4_VERSION?=		4.3.0

_QT_COMPONENTS_ALL=	accessible assistant assistantclient codecs-cn \
			codecs-jp codecs-kr codecs-tw corelib dbus designer \
			doc gui iconengines imageformats inputmethods linguist \
			makeqpf moc network opengl pixeltool porting qdbusviewer \
			qmake qt3support qtconfig qtestlib qvfb rcc script sql \
			svg uic uic3 xml

accessible_DEPENDS=	accessibility/qt4-acessible
assistant_DEPENDS=	devel/qt4-assistant
assistantclient_DEPENDS=devel/qt4-libqtassistantclient
assistantclient_NAME=	libQtAssistantClient
codecs-cn_DEPENDS=	chinese/qt4-codecs-cn
codecs-jp_DEPENDS=	japanese/qt4-codecs-jp
codecs-kr_DEPENDS=	korean/qt4-codecs-kr
codecs-tw_DEPENDS=	chinese/qt4-codecs-tw
corelib_DEPENDS=	devel/qt4-corelib
dbus_DEPENDS=		devel/dbus-qt4
designer_DEPENDS=	devel/qt4-designer
doc_DEPENDS=		misc/qt4-doc
gui_DEPENDS=		x11-toolkits/qt4-gui
iconengines_DEPENDS=	graphics/qt4-iconengines
imageformats_DEPENDS=	graphics/qt4-imageformats
inputmethods_DEPENDS=	x11/qt4-inputmethods
linguist_DEPENDS=	devel/qt4-linguist
makeqpf_DEPENDS=	devel/qt4-makeqpf
moc_DEPENDS=		devel/qt4-moc
network_DEPENDS=	net/qt4-network
opengl_DEPENDS=		x11/qt4-opengl
pixeltool_DEPENDS=	graphics/qt4-pixeltool
porting_DEPENDS=	devel/qt4-porting
qdbusviewer_DEPENDS=	devel/qt4-qdbusviewer
qmake_DEPENDS=		devel/qmake4
qmake_QT4_PREFIX=	# empty
qt3support_DEPENDS=	devel/qt4-qt3support
qtconfig_DEPENDS=	devel/qtconfig
qtestlib_DEPENDS=	devel/qt4-qtestlib
qvfb_DEPENDS=		devel/qt4-qvfb
rcc_DEPENDS=		devel/qt4-rcc
script_DEPENDS=		devel/qt4-script
sql_DEPENDS=		databases/qt4-sql
svg_DEPENDS=		graphics/qt4-svg
uic_DEPENDS=		devel/qt4-uic
uic3_DEPENDS=		devel/qt4-uic3
xml_DEPENDS=		textproc/qt4-xml

.if defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)
Qt_Post_Include= bsd.qt.mk

.if defined(QT_COMPONENTS)
.for ext in ${QT_COMPONENTS}
${ext}_QT4_PREFIX?=     qt4-
${ext}_QT4_VERSION?=    ${QT4_VERSION}
${ext}_NAME?=           ${ext}
.if ${_QT_COMPONENTS_ALL:M${ext}}!= ""
BUILD_DEPENDS+= ${${ext}_QT4_PREFIX}${${ext}_NAME}>=${${ext}_QT4_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
RUN_DEPENDS+=   ${${ext}_QT4_PREFIX}${${ext}_NAME}>=${${ext}_QT4_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
.else
IGNORE= cannot install: unknown Qt4 component -- ${ext}
.endif
.endfor
.else
BUILD_DEPENDS+=         qt4>=${QT4_VERSION}:${PORTSDIR}/devel/qt4
RUN_DEPENDS+=           qt4>=${QT4_VERSION}:${PORTSDIR}/devel/qt4
.endif

.endif
