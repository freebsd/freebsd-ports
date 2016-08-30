# $FreeBSD$
#
# Provides support for KDE-based ports.
#
# Feature:	kde
# Usage:	USES=kde:ARGS
# Valid ARGS:	4
#
# 4: 		Depend on KDE4 components and variables.
#
# Variables that can be set by a port:
#
# USE_KDE	List of KDE4 components (other ports) that this
#		port depends on.
#		* foo_build	Add a build-time dependency (BUILD_DEPENDS)
#		* foo_run	Add a run-time dependency (RUN_DEPENDS)
#		* foo (default)	Add both dependencies on component <foo>
#
# MAINTAINER:	kde@FreeBSD.org

.if !defined(_INCLUDE_USES_KDE_MK)
_INCLUDE_USES_KDE_MK=	yes

_KDE_SUPPORTED=		4

.  if empty(kde_ARGS)
IGNORE=	kde needs a version (${_KDE_SUPPORTED})
.  endif

# At the moment we support KDE versions 4.
.  for ver in ${_KDE_SUPPORTED:O:u}
.    if ${kde_ARGS:M${ver}}
.      if !defined(_KDE_VERSION)
_KDE_VERSION=	${ver}
.      else
IGNORE?=	cannot be installed: different KDE versions specified via kde:[${_KDE_SUPPORTED:S/ //g}] #'
.      endif
.    endif
.  endfor

.  if empty(_KDE_VERSION)
IGNORE?=	kde:[${_KDE_SUPPORTED:S/ //g}] needs an argument  #'
.  endif

_KDE_RELNAME=           KDE${_KDE_VERSION}

# === VERSIONS OF THE DIFFERENT COMPONENTS =====================================
# Old KDE desktop.
KDE4_VERSION?=			4.14.3
KDE4_KDELIBS_VERSION=		4.14.10
KDE4_ACTIVITIES_VERSION=	4.13.3
KDE4_WORKSPACE_VERSION=		4.11.21
KDE4_KDEPIM_VERSION?=		4.14.10
# Applications version for the kde4-applications.
KDE4_APPLICATIONS_BRANCH?=	Attic
KDE4_APPLICATIONS_VERSION?=	15.04.3
KDE4_BRANCH?=			stable

# Extended KDE universe applications.
CALLIGRA_VERSION?=		2.9.11
CALLIGRA_BRANCH?=		stable

KDEVELOP_VERSION?=		4.7.3
KDEVELOP_BRANCH?=		stable

KTP_VERSION?=			0.9.0
KTP_BRANCH?=			stable
# ==============================================================================

# === INSTALLATION PREFIX ======================================================
# Define installation prefix.
KDE_PREFIX=	${LOCALBASE}
# ==============================================================================

# ==== SETUP CMAKE ENVIRONMENT =================================================
# Help cmake to find files when testing ports with non-default PREFIX.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH="${LOCALBASE}"

.  if ${_KDE_VERSION:M*4*}
CMAKE_ARGS+=	-DKDE4_BUILD_TESTS:BOOL=OFF
.  endif

# Set man-page installation prefix.
CMAKE_ARGS+=	-DKDE_INSTALL_MANDIR:PATH="${KDE_PREFIX}/man" \
		-DMAN_INSTALL_DIR:PATH="${KDE_PREFIX}/man"
# ==============================================================================

# === SET-UP PLIST_SUB =========================================================
# Prefix and include directory.
PLIST_SUB+=		KDE_PREFIX="${KDE_PREFIX}"
# KDE Applications version.
PLIST_SUB+=		KDE_APPLICATIONS_VERSION="${KDE_APPLICATIONS_VERSION}"
# For KDE4 applications provide KDE4 version numbers.
.  if ${_KDE_VERSION:M*4*}
PLIST_SUB+=		KDE4_VERSION="${KDE4_VERSION}" \
			KDE4_GENERIC_LIB_VERSION=${KDE4_KDELIBS_VERSION} \
			KDE4_NON_GENERIC_LIB_VERSION=${KDE4_KDELIBS_VERSION:S,^4,5,} \
			KDE4_KDELIBS_VERSION=${KDE4_KDELIBS_VERSION} \
			KDE4_NG_KDELIBS_VERSION=${KDE4_KDELIBS_VERSION:S,^4,5,}
.  endif
# ==============================================================================

# === HANDLE PYTHON ============================================================
# TODO: Keep in sync with cmake/modules/PythonMacros.cmake
_PYTHON_SHORT_VER=	${PYTHON_VERSION:S/^python//:S/.//}
.  if ${_PYTHON_SHORT_VER} > 31
PLIST_SUB+=		PYCACHE="__pycache__/" \
			PYC_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyc \
			PYO_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyo
.  else
PLIST_SUB+=		PYCACHE="" \
			PYC_SUFFIX=pyc \
			PYO_SUFFIX=pyo
.  endif
# ==============================================================================
_USE_KDE4_ALL=  	baloo baloo-widgets baseapps kactivities kate kdelibs \
			kfilemetadata korundum libkcddb libkcompactdisc \
			libkdcraw libkdeedu libkdegames libkexiv2 libkipi \
			libkonq libksane marble nepomuk-core nepomuk-widgets \
			okular oxygen-icons4 perlkde perlqt pimlibs pykde4 \
			pykdeuic4 qtruby runtime smokegen smokekde smokeqt \
			workspace
# These components are not part of the Software Compilation.
_USE_KDE4_ALL+=		akonadi attica automoc4 ontologies qimageblitz soprano \
			strigi

# ====================== kde4 components =======================================
baloo_PORT=		sysutils/baloo
baloo_LIB=		libbaloocore.so

baloo-widgets_PORT=	sysutils/baloo-widgets
baloo-widgets_LIB=	libbaloowidgets.so

baseapps_PORT=		x11/kde4-baseapps
baseapps_PATH=		${KDE_PREFIX}/bin/kfmclient
baseapps_TYPE=		run

kactivities_PORT=	x11/kactivities
kactivities_LIB=	libkactivities.so

kate_PORT=		editors/kate
kate_LIB=		libkateinterfaces.so

kdelibs_PORT=		x11/kdelibs4
kdelibs_LIB=		libkdecore.so

kfilemetadata_PORT=	sysutils/kfilemetadata
kfilemetadata_LIB=	libkfilemetadata.so

korundum_PORT=		devel/ruby-korundum
korundum_PATH=		${KDE_PREFIX}/lib/kde4/krubypluginfactory.so
korundum_TYPE=		run

libkcddb_PORT=		audio/libkcddb
libkcddb_LIB=		libkcddb.so

libkcompactdisc_PORT=	audio/libkcompactdisc
libkcompactdisc_LIB=	libkcompactdisc.so

libkdcraw_PORT=		graphics/libkdcraw-kde4
libkdcraw_LIB=		libkdcraw.so

libkdeedu_PORT=		misc/libkdeedu
libkdeedu_LIB=		libkeduvocdocument.so

libkdegames_PORT=	games/libkdegames
libkdegames_LIB=	libkdegames.so

libkexiv2_PORT=		graphics/libkexiv2-kde4
libkexiv2_LIB=		libkexiv2.so

libkipi_PORT=		graphics/libkipi-kde4
libkipi_LIB=		libkipi.so

libkonq_PORT=		x11/libkonq
libkonq_LIB=		libkonq.so

libksane_PORT=		graphics/libksane
libksane_LIB=		libksane.so

marble_PORT=		astro/marble
marble_LIB=		libmarblewidget.so

nepomuk-core_PORT=	sysutils/nepomuk-core
nepomuk-core_LIB=	libnepomukcore.so

nepomuk-widgets_PORT=	sysutils/nepomuk-widgets
nepomuk-widgets_LIB=	libnepomukwidgets.so

okular_PORT=		graphics/okular
okular_LIB=		libokularcore.so

oxygen-icons4_PORT=	x11-themes/kde4-icons-oxygen
oxygen-icons4_PATH=	${KDE_PREFIX}/share/icons/oxygen/index.theme
oxygen-icons4_TYPE=	run

perlkde_PORT=		devel/p5-perlkde
perlkde_PATH=		${KDE_PREFIX}/lib/kde4/kperlpluginfactory.so
perlkde_TYPE=		run

perlqt_PORT=		devel/p5-perlqt
perlqt_PATH=		${KDE_PREFIX}/bin/puic4

pimlibs_PORT=		deskutils/kdepimlibs4
pimlibs_LIB=		libkpimutils.so

pykde4_PORT=		devel/py-pykde4
pykde4_PATH=		${KDE_PREFIX}/lib/kde4/kpythonpluginfactory.so
pykde4_TYPE=		run

pykdeuic4_PORT=		devel/py-pykdeuic4
pykdeuic4_PATH=		${LOCALBASE}/bin/pykdeuic4
pykdeuic4_TYPE=		run

qtruby_PORT=		devel/ruby-qtruby
qtruby_LIB=		libqtruby4shared.so

runtime_PORT=		x11/kde4-runtime
runtime_PATH=		${KDE_PREFIX}/bin/knotify4
runtime_TYPE=		run

smokegen_PORT=		devel/smokegen
smokegen_LIB=		libsmokebase.so

smokekde_PORT=		devel/smokekde
smokekde_LIB=		libsmokekdecore.so

smokeqt_PORT=		devel/smokeqt
smokeqt_LIB=		libsmokeqtcore.so

workspace_PORT=		x11/kde4-workspace
workspace_LIB=		libkworkspace.so

# Non-Software Compilation components
akonadi_PORT=		databases/akonadi
akonadi_LIB=		libakonadiprotocolinternals.so

attica_PORT=		x11-toolkits/attica
attica_LIB=		libattica.so

automoc4_PORT=		devel/automoc4
automoc4_PATH=		${LOCALBASE}/bin/automoc4
automoc4_TYPE=		build

ontologies_PORT=	x11-toolkits/shared-desktop-ontologies
ontologies_PATH=	${LOCALBASE}/share/ontology/core/rdf.ontology

qimageblitz_PORT=	x11/qimageblitz
qimageblitz_LIB=	libqimageblitz.so

soprano_PORT=		textproc/soprano
soprano_LIB=		libsoprano.so

strigi_PORT=		deskutils/libstreamanalyzer
strigi_LIB=		libstreamanalyzer.so.0
# ====================== end of kde4 components ================================

# end of component list ########################################################

_USE_KDE_ALL=	${_USE_${_KDE_RELNAME}_ALL}

# Iterate through components deprived of suffix.
.  for component in ${USE_KDE:O:u:C/_.+//}
  # Check that the component is valid.
.    if ${_USE_KDE_ALL:M${component}} != ""
   # Skip meta-components (currently none).
.      if defined(${component}_PORT) && (defined(${component}_PATH) || defined(${component}_LIB))
    # Check if a dependency type is explicitly requested.
.        if ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
${component}_TYPE=	# empty
.          if ${USE_KDE:M${component}_build} != ""
${component}_TYPE+=	build
.          endif
.          if ${USE_KDE:M${component}_run} != ""
${component}_TYPE+=	run
.          endif
.        endif # ${USE_KDE:M${component}_*} != "" && ${USE_KDE:M${component}} == ""
    # If no dependency type is set, default to full dependency.
.        if !defined(${component}_TYPE)
${component}_TYPE=	build run
.        endif
    # Set real dependencies.
.        if defined(${component}_LIB) && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
LIB_DEPENDS+=		${${component}_LIB}:${${component}_PORT}
.        else
${component}_PATH?=	${KDE_PREFIX}/lib/${${component}_LIB}
${component}_DEPENDS=	${${component}_PATH}:${${component}_PORT}
.          if ${${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=		${${component}_DEPENDS}
.          endif
.          if ${${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=		${${component}_DEPENDS}
.          endif
.        endif # ${${component}_LIB} && ${${component}_TYPE:Mbuild} && ${${component}_TYPE:Mrun}
.      endif # defined(${component}_PORT) && defined(${component}_PATH)
.    else # ! ${_USE_KDE_ALL:M${component}} != ""
IGNORE=				cannot be installed: unknown USE_KDE component '${component}'
.    endif # ${_USE_KDE_ALL:M${component}} != ""
.  endfor

.endif
