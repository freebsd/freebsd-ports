#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# Variables:
# QT_NONSTANDARD	- Suppress modification of configure and make environment.
# QT_DIST		- Package being built is part of the Qt distribution.
#
# Global switches (add this to /etc/make.conf):
# WITH_QT_PHONON	- If set, Qt phonon will be used instead of standalone.
#				Qt phonon doesn't work with KDE 4.4.
# QT4_OPTIONS		- A list of options, can be CUPS, NAS and/or QGTKSTYLE.
#				If set, Qt will be built with support for:
#				- Common UNIX Printing System (CUPS);
#				- Network Audio System (NAS);
#				- Qt style that renders using GTK (QGTKSTYLE).

.if !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)
Qt_Include_MAINTAINER=	kde@FreeBSD.org
Qt_Pre_Include=		bsd.qt.mk

.if !defined(QT_NONSTANDARD)
CONFIGURE_ARGS+=--with-qt-includes=${QT_INCDIR} \
		--with-qt-libraries=${QT_LIBDIR} \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include
CONFIGURE_ENV+=	MOC="${MOC}" UIC="${UIC}" LIBS="${QTCFGLIBS}" \
		QMAKE="${QMAKE}" QMAKESPEC="${QMAKESPEC}" QTDIR="${QT_PREFIX}"
CPPFLAGS+=	${QTCPPFLAGS}
MAKE_ENV+=	QMAKESPEC="${QMAKESPEC}"
.endif # !defined(QT_NONSTANDARD)

.if defined(QT_DIST)
DISTINFO_FILE=	${PORTSDIR}/devel/qt4/distinfo
MASTER_SITES=	${MASTER_SITE_QT}
DISTNAME=	qt-everywhere-opensource-src-${QT4_VERSION}
DIST_SUBDIR=	KDE
#CONFLICTS+=	Currently there are no conflicts \o/

# Let configure handle its well known compilers defined in the mkspecs
# (i.e. `cc` and `c++` are not supported by configure tests).
CONFIGURE_ENV+=	CC="" CXX=""

# Keep in sync with devel/qmake4/files/qconfig.cpp
CONFIGURE_ARGS+=-fast -platform ${QMAKESPEC} \
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
		-importdir ${PREFIX}/${QT_LIBDIR_REL}/imports \
		-datadir ${PREFIX}/share/qt4 \
		-translationdir ${PREFIX}/share/qt4/translations \
		-sysconfdir ${PREFIX}/etc/xdg \
		-examplesdir ${PREFIX}/share/examples/qt4/examples \
		-demosdir ${PREFIX}/share/examples/qt4/demos \
		-phonon \
		-no-phonon-backend

PLIST_SUB+=	SHLIB_VER=${QT4_VERSION:C/-.*//} \
		SHLIB_SHVER=${QT4_VERSION:R}

.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=-no-mmx -no-3dnow -no-sse -no-sse2 -no-sse3 \
		-no-ssse3 -no-sse4.1 -no-sse4.2
.endif #defined(PACKAGE_BUILDING)

# .if defined(PORTNAME) && ${PORTNAME} != "xmlpatterns"
# CONFIGURE_ARGS+=-no-exceptions
# .endif

.if defined(WANT_QT_DEBUG) || defined(WITH_DEBUG)
CONFIGURE_ARGS+=-debug -separate-debug-info
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
RCC?=		${QT_PREFIX}/bin/rcc
QMAKE?=		${QT_PREFIX}/bin/qmake-qt4
QMAKEFLAGS+=	QMAKE_CC="${CC}" QMAKE_CXX="${CXX}" \
		QMAKE_LINK="${CXX}" QMAKE_LINK_SHLIB="${CXX}" \
		QMAKE_LINK_C="${CC}" QMAKE_LINK_C_SHLIB="${CC}" \
		QMAKE_CFLAGS="${CFLAGS}" QMAKE_CXXFLAGS="${CXXFLAGS}" \
		QMAKE_CFLAGS_THREAD="${PTHREAD_CFLAGS}" \
		QMAKE_LFLAGS_THREAD="${PTHREAD_LIBS}"

#
# Translate `c++` to its real name and select the appropriate mkspec.
#
QMAKE_BASE_COMPILER!=	cc --version 2> /dev/null | ${AWK} 'NR == 1 { gsub(/[()]/, "", $$2); print $$2 }'
.if ${QMAKE_BASE_COMPILER:L} == "gcc"
QMAKE_BASE_COMPILER=	g++
.endif
.if ${CXX} == "c++"
# Why CXX instead of CXX:T? Because if you're setting the full path of
# `c++` you probably want to define QMAKESPEC by hand too.
QMAKE_COMPILER=	${QMAKE_BASE_COMPILER}
.elif ${CXX:T} == "clang++"
QMAKE_COMPILER=	clang
.elif ${CXX:C/c\+\+/g++/:T} == "llvm-g++"
QMAKE_COMPILER=	llvm
.elif ${CXX:T} == "icpc"
QMAKE_COMPILER=	icc
.else
# Handle all the other cases (mainly g++*).
QMAKE_COMPILER=	${CXX:C/c\+\+/g++/:T}
.endif
.if exists(${QT_PREFIX}/share/qt4/mkspecs/freebsd-${QMAKE_COMPILER})
QMAKESPEC?=	${QT_PREFIX}/share/qt4/mkspecs/freebsd-${QMAKE_COMPILER}
.else
# If something went wrong, default to the base configuration.
QMAKESPEC?=	${QT_PREFIX}/share/qt4/mkspecs/freebsd-${QMAKE_BASE_COMPILER}
.endif

QTCPPFLAGS?=
QTCGFLIBS?=

.endif # !defined(_POSTMKINCLUDED) && !defined(Qt_Pre_Include)

#
# QT4 version
#
QT4_VERSION?=		4.7.4

_QT_COMPONENTS_ALL=	accessible assistant assistant-adp assistantclient \
			clucene codecs-cn codecs-jp codecs-kr codecs-tw corelib \
			dbus declarative demo designer doc \
			graphicssystems-opengl gui help help-tools \
			iconengines imageformats inputmethods \
			linguist l10n makeqpf moc multimedia network opengl \
			pixeltool porting phonon phonon-gst \
			qdbusviewer qdoc3 qmake qt3support qtconfig qtestlib \
			qvfb rcc script scripttools sql sql-ibase sql-mysql \
			sql-odbc sql-pgsql sql-sqlite2 sql-sqlite3 svg uic uic3 \
			webkit xml xmlpatterns xmlpatterns-tool

accessible_PORT=	accessibility/qt4-accessible
accessible_DEPENDS=	${QT_PLUGINDIR}/accessible/libqtaccessiblewidgets.so

assistant_PORT=		devel/qt4-assistant
assistant_DEPENDS=	${QT_PREFIX}/bin/assistant-qt4

assistant-adp_PORT=	devel/qt4-assistant-adp
assistant-adp_DEPENDS=	${QT_PREFIX}/bin/assistant_adp

assistantclient_PORT=		devel/qt4-libqtassistantclient
assistantclient_DEPENDS=	${QT_LIBDIR}/libQtAssistantClient.so

clucene_PORT=		textproc/qt4-clucene
clucene_DEPENDS=	${QT_LIBDIR}/libQtCLucene.so

codecs-cn_PORT=		chinese/qt4-codecs-cn
codecs-cn_DEPENDS=	${QT_PLUGINDIR}/codecs/libqcncodecs.so

codecs-jp_PORT=		japanese/qt4-codecs-jp
codecs-jp_DEPENDS=	${QT_PLUGINDIR}/codecs/libqjpcodecs.so

codecs-kr_PORT=		korean/qt4-codecs-kr
codecs-kr_DEPENDS=	${QT_PLUGINDIR}/codecs/libqkrcodecs.so

codecs-tw_PORT=		chinese/qt4-codecs-tw
codecs-tw_DEPENDS=	${QT_PLUGINDIR}/codecs/libqtwcodecs.so

corelib_PORT=		devel/qt4-corelib
corelib_DEPENDS=	${QT_LIBDIR}/libQtCore.so

dbus_PORT=	devel/dbus-qt4
dbus_DEPENDS=	${QT_LIBDIR}/libQtDBus.so

declarative_PORT=	devel/qt4-declarative
declarative_DEPENDS=	${QT_LIBDIR}/libQtDeclarative.so

demo_PORT=	misc/qt4-qtdemo
demo_DEPENDS=	${QT_PREFIX}/bin/qtdemo

designer_PORT=		devel/qt4-designer
designer_DEPENDS=	${QT_PREFIX}/bin/designer-qt4

doc_PORT=	misc/qt4-doc
doc_DEPENDS=	qt4-doc>=4

graphicssystems-opengl_PORT=	x11/qt4-graphicssystems-opengl
graphicssystems-opengl_DEPENDS=	${QT_PLUGINDIR}/graphicssystems/libqglgraphicssystem.so

gui_PORT=	x11-toolkits/qt4-gui
gui_DEPENDS=	${QT_LIBDIR}/libQtGui.so

help_PORT=	devel/qt4-help
help_DEPENDS=	${QT_LIBDIR}/libQtHelp.so

help-tools_PORT=	devel/qt4-help-tools
help-tools_DEPENDS=	${QT_PREFIX}/bin/qhelpgenerator

iconengines_PORT=	graphics/qt4-iconengines
iconengines_DEPENDS=	${QT_PLUGINDIR}/iconengines/libqsvgicon.so

imageformats_PORT=	graphics/qt4-imageformats
imageformats_DEPENDS=	${QT_PLUGINDIR}/imageformats/libqjpeg.so

inputmethods_PORT=	x11/qt4-inputmethods
inputmethods_DEPENDS=	${QT_PLUGINDIR}/inputmethods/libqimsw-multi.so

linguist_PORT=		devel/qt4-linguist
linguist_DEPENDS=	${QT_PREFIX}/bin/linguist-qt4

l10n_PORT=	misc/qt4-l10n
l10n_DEPENDS=	qt4-l10n>=4

makeqpf_PORT=		devel/qt4-makeqpf
makeqpf_DEPENDS=	${QT_PREFIX}/bin/makeqpf-qt4

moc_PORT=	devel/qt4-moc
moc_DEPENDS=	${MOC}

multimedia_PORT=	multimedia/qt4-multimedia
multimedia_DEPENDS=	${QT_LIBDIR}/libQtMultimedia.so

network_PORT=		net/qt4-network
network_DEPENDS=	${QT_LIBDIR}/libQtNetwork.so

opengl_PORT=	x11/qt4-opengl
opengl_DEPENDS=	${QT_LIBDIR}/libQtOpenGL.so

pixeltool_PORT=		graphics/qt4-pixeltool
pixeltool_DEPENDS=	${QT_PREFIX}/bin/pixeltool

.if !defined(WITH_QT_PHONON)
phonon_PORT=	multimedia/phonon
.else
phonon_PORT=	multimedia/qt4-phonon
.endif
phonon_DEPENDS=	${QT_LIBDIR}/libphonon.so

.if !defined(WITH_QT_PHONON)
phonon-gst_PORT=	multimedia/phonon-gstreamer
.else
phonon-gst_PORT=	multimedia/qt4-phonon-gst
.endif
phonon-gst_DEPENDS=	${QT_PLUGINDIR}/phonon_backend/libphonon_gstreamer.so

porting_PORT=		devel/qt4-porting
porting_DEPENDS=	${QT_PREFIX}/bin/qt3to4

qdbusviewer_PORT=	devel/qt4-qdbusviewer
qdbusviewer_DEPENDS=	${QT_PREFIX}/bin/qdbusviewer

qdoc3_PORT=	devel/qt4-qdoc3
qdoc3_DEPENDS=	${QT_PREFIX}/bin/qdoc3

qmake_PORT=	devel/qmake4
qmake_DEPENDS=	${QMAKE}

qt3support_PORT=	devel/qt4-qt3support
qt3support_DEPENDS=	${QT_LIBDIR}/libQt3Support.so

qtconfig_PORT=		misc/qt4-qtconfig
qtconfig_DEPENDS=	${QT_PREFIX}/bin/qtconfig-qt4

qtestlib_PORT=		devel/qt4-qtestlib
qtestlib_DEPENDS=	${QT_LIBDIR}/libQtTest.so

qvfb_PORT=	devel/qt4-qvfb
qvfb_DEPENDS=	${QT_PREFIX}/bin/qvfb-qt4

rcc_PORT=		devel/qt4-rcc
rcc_DEPENDS=		${RCC}

script_PORT=		devel/qt4-script
script_DEPENDS=		${QT_LIBDIR}/libQtScript.so

scripttools_PORT=	devel/qt4-scripttools
scripttools_DEPENDS=	${QT_LIBDIR}/libQtScriptTools.so

sql_PORT=	databases/qt4-sql
sql_DEPENDS=	${QT_LIBDIR}/libQtSql.so

sql-ibase_PORT=		databases/qt4-ibase-plugin
sql-ibase_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlibase.so

sql-mysql_PORT=		databases/qt4-mysql-plugin
sql-mysql_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlmysql.so

sql-odbc_PORT=		databases/qt4-odbc-plugin
sql-odbc_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlodbc.so

sql-pgsql_PORT=		databases/qt4-pgsql-plugin
sql-pgsql_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlpsql.so

sql-sqlite2_PORT=	databases/qt4-sqlite-plugin
sql-sqlite2_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlite2.so

sql-sqlite3_PORT=	databases/qt4-sqlite3-plugin
sql-sqlite3_DEPENDS=	${QT_PLUGINDIR}/sqldrivers/libqsqlite.so

svg_PORT=	graphics/qt4-svg
svg_DEPENDS=	${QT_LIBDIR}/libQtSvg.so

uic_PORT=	devel/qt4-uic
uic_DEPENDS=	${UIC}

uic3_PORT=	devel/qt4-uic3
uic3_DEPENDS=	${QT_PREFIX}/bin/uic3

webkit_PORT=	www/qt4-webkit
webkit_DEPENDS=	${QT_LIBDIR}/libQtWebKit.so

xml_PORT=	textproc/qt4-xml
xml_DEPENDS=	${QT_LIBDIR}/libQtXml.so

xmlpatterns_PORT=	textproc/qt4-xmlpatterns
xmlpatterns_DEPENDS=	${QT_LIBDIR}/libQtXmlPatterns.so

xmlpatterns-tool_PORT=		textproc/qt4-xmlpatterns-tool
xmlpatterns-tool_DEPENDS=	${QT_PREFIX}/bin/xmlpatterns

.if defined(_POSTMKINCLUDED) && !defined(Qt_Post_Include)
Qt_Post_Include= bsd.qt.mk

.for component in ${_QT_COMPONENTS_ALL}
${component}_BUILD_DEPENDS?=	${${component}_DEPENDS}:${PORTSDIR}/${${component}_PORT}
${component}_RUN_DEPENDS?=	${${component}_DEPENDS}:${PORTSDIR}/${${component}_PORT}

${component}_build_BUILD_DEPENDS?=	${${component}_BUILD_DEPENDS}
${component}_run_RUN_DEPENDS?=		${${component}_RUN_DEPENDS}

_QT_COMPONENTS_ALL_SUFFIXED+=	${component} ${component}_build ${component}_run
.endfor

.if defined(QT_COMPONENTS)
. for component in ${QT_COMPONENTS:O:u}
.  if ${_QT_COMPONENTS_ALL_SUFFIXED:M${component}}!= ""
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.  else
IGNORE=	can't be installed: unknown Qt 4 component '${component}'
.  endif
. endfor
.endif

.endif
