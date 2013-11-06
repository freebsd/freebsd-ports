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
# USE_KDE4=		kdehier kdelibs kdeprefix
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
# baseapps		- Basic applications for KDE Desktop
# kactivities           - KDE activities library
# kate			- KDE text editor framework
# kdehier		- Hierarchy of common KDE directories
# kdelibs		- KDE Developer Platform
# kdeprefix		- If set, port will be installed into ${KDE4_PREFIX} instead of
#			  ${LOCALBASE}
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
# sharedmime		- MIME types database for KDE ports
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

KDE4_VERSION?=		4.10.5
KDE4_BRANCH?=		stable
KTP_VERSION?=		0.6.1
KTP_BRANCH?=		stable
CALLIGRA_VERSION?=	2.6.2
CALLIGRA_BRANCH?=	stable
KDEVELOP_VERSION?=	4.5.2
KDEVELOP_BRANCH?=	stable

#
# KDE4 is installed into its own prefix to avoid conflicting with KDE3.
#

KDE4_PREFIX?=	${LOCALBASE}/kde4

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
		KDE4_VERSION="${KDE4_VERSION}"

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

_USE_KDE4_ALL=		baseapps kactivities kate kdehier kdelibs kdeprefix \
			korundum libkcddb libkcompactdisc libkdcraw libkdeedu \
			libkexiv2 libkdegames libkipi libkonq libksane marble \
			nepomuk-core nepomuk-widgets \
			okular oxygen perlkde perlqt pimlibs pykde4 pykdeuic4 \
			qtruby runtime sharedmime smokegen smokekde smokeqt \
			workspace
# These components are not part of the Software Compilation.
_USE_KDE4_ALL+=		akonadi attica automoc4 ontologies qimageblitz soprano \
			strigi

baseapps_PORT=		x11/kde4-baseapps
baseapps_PATH=		${KDE4_PREFIX}/bin/kfmclient
baseapps_TYPE=		run

kactivities_PORT=	x11/kactivities
kactivities_PATH=	${KDE4_PREFIX}/lib/libkactivities.so.6

kate_PORT=		editors/kate
kate_PATH=		${KDE4_PREFIX}/lib/libkateinterfaces.so.5

kdehier_PORT=		misc/kdehier4
kdehier_PATH=		kdehier4>=0
kdehier_TYPE=		run

kdelibs_PORT=		x11/kdelibs4
kdelibs_PATH=		${KDE4_PREFIX}/lib/libkdecore.so.7

korundum_PORT=		devel/ruby-korundum
korundum_PATH=		${KDE4_PREFIX}/lib/kde4/krubypluginfactory.so
korundum_TYPE=		run

libkcddb_PORT=		audio/libkcddb
libkcddb_PATH=		${KDE4_PREFIX}/lib/libkcddb.so.5

libkcompactdisc_PORT=	audio/libkcompactdisc
libkcompactdisc_PATH=	${KDE4_PREFIX}/lib/libkcompactdisc.so.5

libkdcraw_PORT=		graphics/libkdcraw-kde4
libkdcraw_PATH=		${KDE4_PREFIX}/lib/libkdcraw.so.22

libkdeedu_PORT=		misc/libkdeedu
libkdeedu_PATH=		${KDE4_PREFIX}/lib/libkeduvocdocument.so.5

libkdegames_PORT=	games/libkdegames
libkdegames_PATH=	${KDE4_PREFIX}/lib/libkdegames.so.6

libkexiv2_PORT=		graphics/libkexiv2-kde4
libkexiv2_PATH=		${KDE4_PREFIX}/lib/libkexiv2.so.11

libkipi_PORT=		graphics/libkipi-kde4
libkipi_PATH=		${KDE4_PREFIX}/lib/libkipi.so.10

libkonq_PORT=		x11/libkonq
libkonq_PATH=		${KDE4_PREFIX}/lib/libkonq.so.7

libksane_PORT=		graphics/libksane
libksane_PATH=		${KDE4_PREFIX}/lib/libksane.so.0

marble_PORT=		astro/marble
marble_PATH=		${KDE4_PREFIX}/lib/libmarblewidget.so.15

nepomuk-core_PORT=	sysutils/nepomuk-core
nepomuk-core_PATH=	${KDE4_PREFIX}/lib/libnepomukcore.so.5

nepomuk-widgets_PORT=	sysutils/nepomuk-widgets
nepomuk-widgets_PATH=	${KDE4_PREFIX}/lib/libnepomukwidgets.so.5

okular_PORT=		graphics/okular
okular_PATH=		${KDE4_PREFIX}/lib/libokularcore.so.2

oxygen_PORT=		x11-themes/kde4-icons-oxygen
oxygen_PATH=		${KDE4_PREFIX}/share/icons/oxygen/index.theme
oxygen_TYPE=		run

perlkde_PORT=		devel/p5-perlkde
perlkde_PATH=		${KDE4_PREFIX}/lib/kde4/kperlpluginfactory.so
perlkde_TYPE=		run

perlqt_PORT=		devel/p5-perlqt
perlqt_PATH=		${KDE4_PREFIX}/bin/puic4

pimlibs_PORT=		deskutils/kdepimlibs4
pimlibs_PATH=		${KDE4_PREFIX}/lib/libkpimutils.so.5

pykde4_PORT=		devel/py-pykde4
pykde4_PATH=		${KDE4_PREFIX}/lib/kde4/kpythonpluginfactory.so
pykde4_TYPE=		run

pykdeuic4_PORT=		devel/py-pykdeuic4
pykdeuic4_PATH=		${LOCALBASE}/bin/pykdeuic4
pykdeuic4_TYPE=		run

qtruby_PORT=		devel/ruby-qtruby
qtruby_PATH=		${KDE4_PREFIX}/lib/libqtruby4shared.so.2

runtime_PORT=		x11/kde4-runtime
runtime_PATH=		${KDE4_PREFIX}/bin/knotify4
runtime_TYPE=		run

sharedmime_PORT=	misc/kde4-shared-mime-info
sharedmime_PATH=	kde4-shared-mime-info>=0

smokegen_PORT=		devel/smokegen
smokegen_PATH=		${KDE4_PREFIX}/lib/libsmokebase.so.3

smokekde_PORT=		devel/smokekde
smokekde_PATH=		${KDE4_PREFIX}/lib/libsmokekdecore.so.3

smokeqt_PORT=		devel/smokeqt
smokeqt_PATH=		${KDE4_PREFIX}/lib/libsmokeqtcore.so.3

workspace_PORT=		x11/kde4-workspace
workspace_PATH=		${KDE4_PREFIX}/lib/libkworkspace.so.5

akonadi_PORT=		databases/akonadi
akonadi_PATH=		${KDE4_PREFIX}/lib/libakonadiprotocolinternals.so.1

attica_PORT=		x11-toolkits/attica
attica_PATH=		${LOCALBASE}/lib/libattica.so.0

automoc4_PORT=		devel/automoc4
automoc4_PATH=		${LOCALBASE}/bin/automoc4
automoc4_TYPE=		build

ontologies_PORT=	x11-toolkits/shared-desktop-ontologies
ontologies_PATH=	${LOCALBASE}/share/ontology/core/rdf.ontology

qimageblitz_PORT=	x11/qimageblitz
qimageblitz_PATH=	${LOCALBASE}/lib/libqimageblitz.so.4

soprano_PORT=		textproc/soprano
soprano_PATH=		${LOCALBASE}/lib/libsoprano.so.4

strigi_PORT=		deskutils/libstreamanalyzer
strigi_PATH=		${LOCALBASE}/lib/libstreamanalyzer.so.0

# Iterate through components deprived of suffix.
.for component in ${USE_KDE4:O:u:C/_.+//}
  # Check that the component is valid.
. if ${_USE_KDE4_ALL:M${component}} != ""
   # Skip meta-components (e.g., kdeprefix).
.  if defined(${component}_PORT) && defined(${component}_PATH)
${component}_DEPENDS=	${${component}_PATH}:${PORTSDIR}/${${component}_PORT}
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

.if defined(USE_KDE4) && ${USE_KDE4:Msharedmime} != ""
post-install:	post-install-sharedmime
. if !target(post-install-sharedmime)
post-install-sharedmime:
.  if defined(NO_STAGE)
	@-${LOCALBASE}/bin/update-mime-database ${KDE4_PREFIX}/share/mime
.  endif
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-mime-database %D/share/mime > /dev/null || /usr/bin/true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-mime-database %D/share/mime > /dev/null || /usr/bin/true" >> ${TMPPLIST}
. endif
.endif

.endif # defined(_POSTMKINCLUDED) && !defined(Kde_Post_Include)
