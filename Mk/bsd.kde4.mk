#-*- mode: Makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Kde_Pre_Include)

# Please make sure all changes to this file are past through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Kde_Pre_Include=	bsd.kde4.mk
Kde_Include_MAINTAINER=	kde@FreeBSD.org

#
# This file contains some variable definitions that are supposed to
# make your life easier when dealing with ports related to the KDE4
# desktop environment. It's automatically included when USE_KDE4
# is defined in the ports' makefile.
#
# KDE4 related ports can use this as follows:
#
# USE_KDE4=	kdehier kdeprefix kdelibs
# USE_QT_VER=	4
# QT_COMPONENTS=corelib #set additional qt4 components here
#
# .include <bsd.port.mk>
#
# Available KDE4 components are:
#
# akonadi	- Akonadi PIM storage service
# automoc4	- automoc4 tool
# kdebase	- Basic KDE applications (Konqueror, Dolphin)
# kdeexp	- experimental libraries (with non-stable ABI/API)
# kdehier	- Provides common KDE directories
# kdelibs	- The base set of KDE4 libraries
# kdeprefix	- If set, port will be installed into ${KDE4_PREFIX} instead of ${LOCALBASE}
# oxygen	- icon themes
# pimlibs	- KDE4 PIM libraries
# pimruntime	- KDE4 PIM runtime services
# runtime	- More KDE applications
# sharedmime	- share-mime-info wrapper for KDE4 ports
# workspace	- More KDE applications (Plasma, kwin, etc.)
#
# These read-only variables can be used in port Makefile:
#
# MASTER_SITE_KDE_kde
#		- MASTER_SITE_KDE_kde is equivalent to MASTER_SITE_KDE
#		with :kde tag. It could be used when port needs multiple
#		distfiles from different sites. See for details porters-handbook:
#		http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/makefile-distfiles.html
# KDE4_PREFIX	- The place where KDE4 ports live. Currently it is {LOCALBASE}/kde4,
#		but this could be changed in a future.
#

KDE4_VERSION=		4.4.4
KDE4_BRANCH?=		stable
KOFFICE2_VERSION=	2.2.0
KOFFICE2_BRANCH?=	stable
KDEVELOP_VERSION=	4.0.0
KDEVELOP_BRANCH?=	stable

#
# KDE4 is installed into its own prefix to not conflict with KDE3
#
KDE4_PREFIX?=		${LOCALBASE}/kde4

#
# Tagged MASTER_SITE_KDE
#
kmaster=		${MASTER_SITE_KDE:S@%/@%/:kde@g}
.if !defined(MASTER_SITE_SUBDIR)
MASTER_SITE_KDE_kde=	${kmaster:S@%SUBDIR%/@@g}
.else
ksub=${MASTER_SITE_SUBDIR}
MASTER_SITE_KDE_kde=	${kmaster:S@%SUBDIR%/@${ksub}/@g}
.endif # !defined(MASTER_SITE_SUBDIR)

#
# KDE4 modules
#
_USE_KDE4_ALL=	akonadi automoc4 kdebase kdehier kdelibs kdeprefix \
		oxygen pimlibs pimruntime pykde4 pykdeuic4 runtime \
		sharedmime workspace

akonadi_LIB_DEPENDS=		akonadiprotocolinternals.1:${PORTSDIR}/databases/akonadi

automoc4_BUILD_DEPENDS=		${LOCALBASE}/bin/automoc4:${PORTSDIR}/devel/automoc4

kdebase_LIB_DEPENDS=		konq.7:${PORTSDIR}/x11/kdebase4

kdehier_RUN_DEPENDS=		kdehier4>=1:${PORTSDIR}/misc/kdehier4

kdelibs_LIB_DEPENDS=		kimproxy.5:${PORTSDIR}/x11/kdelibs4

kdeprefix_PREFIX=		${KDE4_PREFIX}

oxygen_RUN_DEPENDS=		${KDE4_PREFIX}/share/icons/oxygen/index.theme:${PORTSDIR}/x11-themes/kde4-icons-oxygen

pimlibs_LIB_DEPENDS=		kpimutils.5:${PORTSDIR}/deskutils/kdepimlibs4

pimruntime_LIB_DEPENDS=		kdepim-copy.5:${PORTSDIR}/deskutils/kdepim4-runtime

pykde4_RUN_DEPENDS=		${KDE4_PYTHON_SITELIBDIR}/PyKDE4/kdeui.so:${PORTSDIR}/devel/kdebindings4-python-pykde4

pykdeuic4_RUN_DEPENDS=		${LOCALBASE}/bin/pykdeuic4:${PORTSDIR}/devel/kdebindings4-python-pykdeuic4

runtime_BUILD_DEPENDS=		${KDE4_PREFIX}/bin/kdebugdialog:${PORTSDIR}/x11/kdebase4-runtime
runtime_RUN_DEPENDS=		${KDE4_PREFIX}/bin/kdebugdialog:${PORTSDIR}/x11/kdebase4-runtime

sharedmime_BUILD_DEPENDS=	kde4-shared-mime-info>=1:${PORTSDIR}/misc/kde4-shared-mime-info
sharedmime_RUN_DEPENDS=		kde4-shared-mime-info>=1:${PORTSDIR}/misc/kde4-shared-mime-info

workspace_LIB_DEPENDS=		kscreensaver.5:${PORTSDIR}/x11/kdebase4-workspace


PLIST_SUB+=	KDE4_PREFIX="${KDE4_PREFIX}"

KDE4_PYTHON_SITELIBDIR=	${PYTHON_SITELIBDIR:S;${PYTHONBASE};${KDE4_PREFIX};}

#
# Common build related stuff for kde4 ports. It's not intended for usage
# in KDE4-dependent ports
#
.if defined(KDE4_BUILDENV)

.if ${OSVERSION} < 700042
BROKEN=		does not build on 6.x. See http://miwi.bsdcrew.de/2009/01/30/status-report-kde-42-and-freebsd-64-support/
.endif

.if ${KDE4_BRANCH} == "unstable"
WITH_DEBUG=yes
.endif

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	debug
.else
CMAKE_BUILD_TYPE=	release
.endif

PLIST_SUB+=	KDE4_VERSION="${KDE4_VERSION}" \
		KDE4_BUILD_TYPE="${CMAKE_BUILD_TYPE}"

USE_LDCONFIG=	yes

USE_CMAKE=	yes
USE_GMAKE=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}
CONFIGURE_WRKSRC=	${CMAKE_SOURCE_PATH}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC?=	${BUILD_WRKSRC}

post-extract:	kde-create-builddir

kde-create-builddir:
	${MKDIR} ${BUILD_WRKSRC}

.endif # KDE4_BUILDENV

.endif #!defined(_POSTMKINCLUDED) && !defined(Kde_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Kde_Post_Include)

Kde_Post_Include=	bsd.kde4.mk

.for component in ${USE_KDE4}
. if ${_USE_KDE4_ALL:M${component}}!=""
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.  if defined(${component}_PREFIX)
.   if ${.MAKEFLAGS:MPREFIX=*}==""
PREFIX=	${${component}_PREFIX}
.    if ${KDE4_PREFIX} != ${LOCALBASE}
NO_MTREE=	yes
.    endif
.   endif
.  endif
. else
IGNORE=	cannot install: Unknown component ${component}
. endif
.endfor

.endif #defined(_POSTMKINCLUDED) && !defined(Kde_Post_Include)
