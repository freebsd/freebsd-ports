# $FreeBSD$

.if !defined(_POSTMKINCLUDED) && !defined(Kde_Pre_Include)

# Please make sure all changes to this file are past through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Kde_Include_MAINTAINER=	kde@FreeBSD.org
Kde_Pre_Include=	bsd.kde4.mk

#
# This file contains some variable definitions that are supposed to make your
# life easier when dealing with ports related to the KDE Software Compilation 4.
# It's automatically included when ${USE_KDE4} is defined in a port's Makefile.
#
# KDE4 related ports can use this as follows:
#
# USE_KDE4=		kdelibs kdeprefix
# USE_QT4=		corelib # Set Qt 4 components here.
#
# .include <bsd.port.mk>
#
# Additionally, '_build' and '_run' suffixes can be used to force components
# dependency type (e.g., 'marble_run'). If no suffix is set, a default
# dependency type will be used. If you want to force both types, add the
# component twice with both suffixes (e.g., 'pykde4_build pykde4_run').
#
# Available KDE4 components are:
#
# baloo			- Baloo core libraries
# baloo-widgets		- Baloo widgets library
# baseapps		- Basic applications for KDE Desktop
# kactivities           - KDE activities library
# kate			- KDE text editor framework
# kdelibs		- KDE Developer Platform
# kdeprefix		- If set, port will be installed into ${KDE4_PREFIX} instead of
#			  ${LOCALBASE}
# kfilemetadata		- KDE library for extracting file metadata
# korundum		- KDE Ruby bindings
# libkcddb		- KDE CDDB library
# libkcompactdisc	- KDE library for interfacing with audio CDs
# libkdcraw		- KDE LibRaw library
# libkdeedu		- Libraries used by KDE educational applications
# libkdegames		- Libraries used by KDE games
# libkexiv2		- KDE Exiv2 library
# libkipi		- KDE Image Plugin Interface
# libkonq		- Konqueror core library
# libksane		- KDE SANE library
# marble		- KDE virtual globe
# okular		- KDE universal document viewer
# nepomuk-core		- Nepomuk core libraries
# nepomuk-widgets	- Nepomuk widgets library
# oxygen		- KDE icon theme
# perlkde		- KDE Perl bindings
# perlqt		- Qt 4 Perl bindings
# pimlibs		- KDE-Pim libraries
# pykde4		- KDE Python bindings
# pykdeuic4		- PyKDE user interface compiler
# qtruby		- Qt 4 Ruby bindings
# runtime		- Components required by many KDE Applications
# smokegen		- SMOKE base libraries
# smokekde		- KDE SMOKE libraries
# smokeqt		- Qt 4 SMOKE libraries
# workspace		- KDE user environments
# akonadi		- Storage server for KDE-Pim
# attica		- Qt library implementing Open Collaboration Services API
# automoc4		- Automatic moc for Qt 4 packages
# ontologies		- Shared ontologies for semantic searching
# qimageblitz		- KDE graphical effects and filters library
# soprano		- Qt 4 RDF framework
# strigi		- Desktop search daemon
#
# These read-only variables can be used in a port's Makefile:
#
# KDE4_PREFIX		- The place where KDE4 ports live. Currently it is
#			  ${LOCALBASE}/kde4, but this could change in the future.
#

KDE4_VERSION?=		4.14.3
KDE4_ACTIVITES_VERSION=	4.13.3
KDE4_WORKSPACE_VERSION=	4.11.14
KDE4_APPLICATIONS_VERSION?=	15.04.3
KDE4_APPLICATIONS_BRANCH?=	Attic
KDE4_BRANCH?=		stable
KTP_VERSION?=		0.9.0
KTP_BRANCH?=		stable
CALLIGRA_VERSION?=	2.9.11
CALLIGRA_BRANCH?=	stable
KDEVELOP_VERSION?=	4.7.3
KDEVELOP_BRANCH?=	stable

KDE4_PREFIX?=	${LOCALBASE}

# Help cmake to find files when testing ports with non-default PREFIX
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH="${LOCALBASE};${KDE4_PREFIX}" \
		-DKDE4_BUILD_TESTS:BOOL=OFF

# ${PREFIX} and ${NO_MTREE} have to be defined in the pre-makefile section.
.if defined(USE_KDE4) && ${USE_KDE4:Mkdeprefix} != ""
. if ${.MAKEFLAGS:MPREFIX=*} == ""
PREFIX=		${KDE4_PREFIX}
.  if ${KDE4_PREFIX} != ${LOCALBASE}
NO_MTREE=	yes
.  endif
. endif
.endif

PLIST_SUB+=	KDE4_PREFIX="${KDE4_PREFIX}" \
		KDE4_VERSION="${KDE4_VERSION}" \
		KDE4_GENERIC_LIB_VERSION=${KDE4_VERSION} \
		KDE4_NON_GENERIC_LIB_VERSION=${KDE4_VERSION:S,^4,5,}

# Keep in sync with cmake/modules/PythonMacros.cmake
_PYTHON_SHORT_VER=	${PYTHON_VERSION:S/^python//:S/.//}
.if ${_PYTHON_SHORT_VER} > 31
PLIST_SUB+=	PYCACHE="__pycache__/" \
		PYC_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyc \
		PYO_SUFFIX=cpython-${_PYTHON_SHORT_VER}.pyo
.else
PLIST_SUB+=	PYCACHE="" \
		PYC_SUFFIX=pyc \
		PYO_SUFFIX=pyo
.endif

.endif # !defined(_POSTMKINCLUDED) && !defined(Kde_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Kde_Post_Include)

Kde_Post_Include=	bsd.kde4.mk

#
# KDE4 components.
# Set ${component}_TYPE to 'build' or 'run' to specify default dependency type
# for ${component}; otherwise, it will default to 'build run'.
#

_USE_KDE4_ALL=		baloo baloo-widgets \
			baseapps kactivities kate kdelibs kfilemetadata \
			korundum libkcddb libkcompactdisc libkdcraw libkdeedu \
			libkexiv2 libkdegames libkipi libkonq libksane marble \
			nepomuk-core nepomuk-widgets \
			okular oxygen perlkde perlqt pimlibs pykde4 pykdeuic4 \
			qtruby runtime smokegen smokekde smokeqt \
			workspace
# These components are not part of the Software Compilation.
_USE_KDE4_ALL+=		akonadi attica automoc4 ontologies qimageblitz soprano \
			strigi
# Meta components
_USE_KDE4_ALL+=		kdeprefix
# Deprecated
_USE_KDE4_ALL+=		kdehier

baloo_PORT=		sysutils/baloo
baloo_PATH=		${KDE4_PREFIX}/lib/libbaloocore.so

baloo-widgets_PORT=	sysutils/baloo-widgets
baloo-widgets_PATH=	${KDE4_PREFIX}/lib/libbaloowidgets.so

baseapps_PORT=		x11/kde4-baseapps
baseapps_PATH=		${KDE4_PREFIX}/bin/kfmclient
baseapps_TYPE=		run

kactivities_PORT=	x11/kactivities
kactivities_PATH=	${KDE4_PREFIX}/lib/libkactivities.so

kate_PORT=		editors/kate
kate_PATH=		${KDE4_PREFIX}/lib/libkateinterfaces.so

kdelibs_PORT=		x11/kdelibs4
kdelibs_PATH=		${KDE4_PREFIX}/lib/libkdecore.so

.if ${KDE4_PREFIX} != ${LOCALBASE}
kdeprefix_PORT=		misc/kdehier4
kdeprefix_PATH=		kdehier4>=1.3
kdeprefix_TYPE=		run
.endif

kfilemetadata_PORT=	sysutils/kfilemetadata
kfilemetadata_PATH=	${KDE4_PREFIX}/lib/libkfilemetadata.so

korundum_PORT=		devel/ruby-korundum
korundum_PATH=		${KDE4_PREFIX}/lib/kde4/krubypluginfactory.so
korundum_TYPE=		run

libkcddb_PORT=		audio/libkcddb
libkcddb_PATH=		${KDE4_PREFIX}/lib/libkcddb.so

libkcompactdisc_PORT=	audio/libkcompactdisc
libkcompactdisc_PATH=	${KDE4_PREFIX}/lib/libkcompactdisc.so

libkdcraw_PORT=		graphics/libkdcraw-kde4
libkdcraw_PATH=		${KDE4_PREFIX}/lib/libkdcraw.so

libkdeedu_PORT=		misc/libkdeedu
libkdeedu_PATH=		${KDE4_PREFIX}/lib/libkeduvocdocument.so

libkdegames_PORT=	games/libkdegames
libkdegames_PATH=	${KDE4_PREFIX}/lib/libkdegames.so

libkexiv2_PORT=		graphics/libkexiv2-kde4
libkexiv2_PATH=		${KDE4_PREFIX}/lib/libkexiv2.so

libkipi_PORT=		graphics/libkipi-kde4
libkipi_PATH=		${KDE4_PREFIX}/lib/libkipi.so

libkonq_PORT=		x11/libkonq
libkonq_PATH=		${KDE4_PREFIX}/lib/libkonq.so

libksane_PORT=		graphics/libksane
libksane_PATH=		${KDE4_PREFIX}/lib/libksane.so

marble_PORT=		astro/marble
marble_PATH=		${KDE4_PREFIX}/lib/libmarblewidget.so

nepomuk-core_PORT=	sysutils/nepomuk-core
nepomuk-core_PATH=	${KDE4_PREFIX}/lib/libnepomukcore.so

nepomuk-widgets_PORT=	sysutils/nepomuk-widgets
nepomuk-widgets_PATH=	${KDE4_PREFIX}/lib/libnepomukwidgets.so

okular_PORT=		graphics/okular
okular_PATH=		${KDE4_PREFIX}/lib/libokularcore.so

oxygen_PORT=		x11-themes/kde4-icons-oxygen
oxygen_PATH=		${KDE4_PREFIX}/share/icons/oxygen/index.theme
oxygen_TYPE=		run

perlkde_PORT=		devel/p5-perlkde
perlkde_PATH=		${KDE4_PREFIX}/lib/kde4/kperlpluginfactory.so
perlkde_TYPE=		run

perlqt_PORT=		devel/p5-perlqt
perlqt_PATH=		${KDE4_PREFIX}/bin/puic4

pimlibs_PORT=		deskutils/kdepimlibs4
pimlibs_PATH=		${KDE4_PREFIX}/lib/libkpimutils.so

pykde4_PORT=		devel/py-pykde4
pykde4_PATH=		${KDE4_PREFIX}/lib/kde4/kpythonpluginfactory.so
pykde4_TYPE=		run

pykdeuic4_PORT=		devel/py-pykdeuic4
pykdeuic4_PATH=		${LOCALBASE}/bin/pykdeuic4
pykdeuic4_TYPE=		run

qtruby_PORT=		devel/ruby-qtruby
qtruby_PATH=		${KDE4_PREFIX}/lib/libqtruby4shared.so

runtime_PORT=		x11/kde4-runtime
runtime_PATH=		${KDE4_PREFIX}/bin/knotify4
runtime_TYPE=		run

smokegen_PORT=		devel/smokegen
smokegen_PATH=		${KDE4_PREFIX}/lib/libsmokebase.so

smokekde_PORT=		devel/smokekde
smokekde_PATH=		${KDE4_PREFIX}/lib/libsmokekdecore.so

smokeqt_PORT=		devel/smokeqt
smokeqt_PATH=		${KDE4_PREFIX}/lib/libsmokeqtcore.so

workspace_PORT=		x11/kde4-workspace
workspace_PATH=		${KDE4_PREFIX}/lib/libkworkspace.so

akonadi_PORT=		databases/akonadi
akonadi_PATH=		${KDE4_PREFIX}/lib/libakonadiprotocolinternals.so

attica_PORT=		x11-toolkits/attica
attica_PATH=		${LOCALBASE}/lib/libattica.so

automoc4_PORT=		devel/automoc4
automoc4_PATH=		${LOCALBASE}/bin/automoc4
automoc4_TYPE=		build

ontologies_PORT=	x11-toolkits/shared-desktop-ontologies
ontologies_PATH=	${LOCALBASE}/share/ontology/core/rdf.ontology

qimageblitz_PORT=	x11/qimageblitz
qimageblitz_PATH=	${LOCALBASE}/lib/libqimageblitz.so

soprano_PORT=		textproc/soprano
soprano_PATH=		${LOCALBASE}/lib/libsoprano.so

strigi_PORT=		deskutils/libstreamanalyzer
strigi_PATH=		${LOCALBASE}/lib/libstreamanalyzer.so.0

# Iterate through components deprived of suffix.
.for component in ${USE_KDE4:O:u:C/_.+//}
  # Check that the component is valid.
. if ${_USE_KDE4_ALL:M${component}} != ""
   # Skip meta-components (e.g. kdeprefix).
.  if defined(${component}_PORT) && defined(${component}_PATH)
${component}_DEPENDS=	${${component}_PATH}:${${component}_PORT}
    # Check if a dependency type is explicitly requested.
.   if ${USE_KDE4:M${component}_*} != "" && ${USE_KDE4:M${component}} == ""
${component}_TYPE=	# empty
.    if ${USE_KDE4:M${component}_build} != ""
${component}_TYPE+=	build
.    endif
.    if ${USE_KDE4:M${component}_run} != ""
${component}_TYPE+=	run
.    endif
.   endif # ${USE_KDE4:M${component}_*} != "" && ${USE_KDE4:M${component}} == ""
    # If no dependency type is set, default to full dependency.
.   if !defined(${component}_TYPE)
${component}_TYPE=	build run
.   endif
    # Set real dependencies.
.   if ${${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=		${${component}_DEPENDS}
.   endif
.   if ${${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=		${${component}_DEPENDS}
.   endif
.  endif # defined(${component}_PORT) && defined(${component}_PATH)
. else # ! ${_USE_KDE4_ALL:M${component}} != ""
IGNORE=				can't be installed: unknown USE_KDE4 component '${component}'
. endif # ${_USE_KDE4_ALL:M${component}} != ""
.endfor

.endif # defined(_POSTMKINCLUDED) && !defined(Kde_Post_Include)
