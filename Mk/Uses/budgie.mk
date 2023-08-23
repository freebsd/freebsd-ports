# This file provides support for the Budgie Desktop related ports.
#
# Feature:      budgie
# Usage:        USES= budgie
# Valid ARGS:   does not require args
#
# Variable which can be set by the port:
# USE_BUDGIE=	List of components
#
# MAINTAINER: desktop@FreeBSD.org

.if !defined(_INCLUDE_USES_BUDGIE_MK)
_INCLUDE_USES_BUDGIE_MK=  yes

.  if !empty(budgie_ARGS)
IGNORE= Incorrect USES+= budgie:${budgie_ARGS} takes no arguments
.  endif

.  if !defined(USE_GITHUB)
_BUDGIE_PROJECT=	${DISTNAME:S/-${DISTVERSIONFULL}//:tl}

WRKSRC?=	${WRKDIR}/${PORTNAME}-${DISTVERSION}

MASTER_SITE_BUDGIE+= \
	https://github.com/BuddiesOfBudgie/%SUBDIR%/releases/download/v${DISTVERSION}/
MASTER_SITE_BUDGIE_SUBDIR=	${_BUDGIE_PROJECT}

MASTER_SITES?=	${MASTER_SITE_BUDGIE}
MASTER_SITE_SUBDIR?=	${MASTER_SITE_BUDGIE_SUBDIR}

DIST_SUBDIR?=	budgie
.  endif

PLIST_SUB+=	BUDGIE_PLUGINSDIR="lib/budgie-desktop/plugins" \
		RAVEN_PLUGINSDIR="lib/budgie-desktop/raven-plugins"

# Available Budgie components are:
_USE_BUDGIE_ALL= libbudgie libmagpie raven screensaver

libbudgie_LIB_DEPENDS=		libbudgie-plugin.so:x11/budgie-desktop

libmagpie_LIB_DEPENDS=		libmagpie-0.so:x11-wm/magpie

raven_LIB_DEPENDS=		libraven.so:x11/budgie-desktop
raven_RUN_DEPENDS=		budgie-desktop>0:x11/budgie-desktop

screensaver_BUILD_DEPENDS=	budgie-screensaver:x11/budgie-screensaver
screensaver_RUN_DEPENDS=	budgie-screensaver>0:x11/budgie-screensaver

.  if defined(USE_BUDGIE)

.    for comp in ${USE_BUDGIE:C/^([^:]+).*/\1/}
.      if empty(_USE_BUDGIE_ALL:M${comp})
IGNORE= cannot install: Unknown component ${comp}
.      else
_USE_BUDGIE+= ${comp}
.      endif
.    endfor

# Remove duplicate components
USE_BUDGIE=   ${_USE_BUDGIE:O:u}

.    for comp in ${USE_BUDGIE}
.      if ${USE_BUDGIE:M${comp}\:build} && defined(${comp}_BUILD_DEPENDS)
BUILD_DEPENDS+= ${${comp}_BUILD_DEPENDS}
.      elif ${USE_BUDGIE:M${comp}\:run} && defined(${comp}_RUN_DEPENDS)
RUN_DEPENDS+= ${${comp}_RUN_DEPENDS}
.      else
.        if defined(${comp}_LIB_DEPENDS)
LIB_DEPENDS+= ${${comp}_LIB_DEPENDS}
.        else
BUILD_DEPENDS+= ${${comp}_BUILD_DEPENDS}
RUN_DEPENDS+= ${${comp}_RUN_DEPENDS}
.        endif
.      endif
.    endfor

.  endif # end of defined(USE_BUDGIE)

.endif # end of !defined(_INCLUDE_USES_BUDGIE_MK)

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_BUDGIE_POST_MK)
_INCLUDE_USES_BUDGIE_POST_MK= yes
.endif
