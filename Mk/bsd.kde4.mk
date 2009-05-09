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
# kdehier	- Provides common KDE directories
# kdelibs	- The base set of KDE4 libraries
# kdeprefix	- If set, port will be installed into ${KDE4_PREFIX} instead of ${LOCALBASE}
# pimlibs	- KDE4 PIM libraries
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

KDE4_VERSION=		4.2.3
KDE4_BRANCH?=		stable

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
				pimlibs runtime sharedmime workspace

akonadi_LIB_DEPENDS=		akonadiprotocolinternals.1:${PORTSDIR}/databases/akonadi

automoc4_BUILD_DEPENDS=		${LOCALBASE}/bin/automoc4:${PORTSDIR}/devel/automoc4

kdebase_LIB_DEPENDS=		konq.7:${PORTSDIR}/x11/kdebase4

kdehier_RUN_DEPENDS=		kdehier4>=1:${PORTSDIR}/misc/kdehier4

kdelibs_LIB_DEPENDS=		kimproxy.5:${PORTSDIR}/x11/kdelibs4

kdeprefix_PREFIX=		${KDE4_PREFIX}

pimlibs_LIB_DEPENDS=		kpimutils.5:${PORTSDIR}/deskutils/kdepimlibs4

runtime_BUILD_DEPENDS=		${KDE4_PREFIX}/bin/kdebugdialog:${PORTSDIR}/x11/kdebase4-runtime
runtime_RUN_DEPENDS=		${KDE4_PREFIX}/bin/kdebugdialog:${PORTSDIR}/x11/kdebase4-runtime

sharedmime_BUILD_DEPENDS=	kde4-shared-mime-info>=1:${PORTSDIR}/misc/kde4-shared-mime-info
sharedmime_RUN_DEPENDS=		kde4-shared-mime-info>=1:${PORTSDIR}/misc/kde4-shared-mime-info

workspace_LIB_DEPENDS=		kscreensaver.5:${PORTSDIR}/x11/kdebase4-workspace

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
# TODO: bsd.cmake.mk should be fixed first
# CMAKE_SOURCE_PATH=	${WRKSRC}
# CONFIGURE_WRKSRC?=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/build
# BUILD_WRKSRC?=	${CONFIGURE_WRKSRC}
# INSTALL_WRKSRC?=	${CONFIGURE_WRKSRC}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build
CMAKE_SOURCE_PATH=	..

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
