# -*- mode: Makefile; tab-width: 4; -*-
# ex: ts=4
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Tcl_Pre_Include)

Tcl_Pre_Include=		bsd.tcl.mk
Tcl_Include_MAINTAINER=	ports@FreeBSD.org

# USE_TCL:		Depend on tcl to run. In case of incompatible APIs of different 
#				TCL versions the version can be specified directly. If version
#				is not specified (USE_TCL=yes) then the latest version is
#				used (8.4 currently).
#				Available values are: 84, 83, 82, 81 and 80.
#
# USE_TK:		Depend on tk to run. In case of incompatible APIs of different
#				TK versions the version can be specified directly. If version
#				is not specified (USE_TK=yes) then the latest version is
#				used (8.4 currently).
#				Available values are: 84, 83, 82, 81 and 80.
##
# TCL_LIBDIR:		Path where tcl libraries can be found
#
# TCL_INCLUDEDIR: 	Path where tcl C headers can be found
##
# TK_LIBDIR:		Path where tk libraries can be found
#
# TK_INCLUDEDIR: 	Path where tk C headers can be found
##
# TCLSH:		Path to tclsh executable respecting tcl version
#
# WISH:			Path to wish executable respecting tk version
##
# PATCH_TCL_SCRIPTS: 	List of tcl scripts that need to be patched to replace
# 				tclsh calls with tclsh${TK_VER} calls. Also note that
# 				post-patch target is used.
#
# PATCH_TK_SCRIPTS: 	List of tcl scripts that need to be patched to replace
# 				wish calls with wish${TK_VER} calls. Also note that
# 				post-patch target is used.

.if defined(USE_TCL) || defined(USE_TCL_BUILD)

_TCL_VERSIONS=	84 83 82 81 80

.if defined(USE_TCL_BUILD)
USE_TCL=	${USE_TCL_BUILD}
_BUILD=		yes
.endif

.if ${USE_TCL} == "yes"
USE_TCL=	84
.endif

TCL_VER:=	${USE_TCL:S/8/8./}

# Special case
.if ${USE_TCL} == "81"
USE_TCL=	tcl81-thread
.endif

_FOUND=		no
.for ver in ${_TCL_VERSIONS}
. if ${USE_TCL} == ${ver}
_FOUND=		yes
.  if defined(_BUILD)
BUILD_DEPENDS+=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${USE_TCL}
.  else
RUN_DEPENDS+=	tclsh${TCL_VER}:${PORTSDIR}/lang/tcl${USE_TCL}
.  endif
TCL_INCLUDEDIR=	${LOCALBASE}/include/tcl${TCL_VER}
TCL_LIBDIR=		${LOCALBASE}/lib/tcl${TCL_VER}
TCLSH=			${LOCALBASE}/bin/tclsh${TCL_VER}
. endif
.endfor

.if ${_FOUND} == "no"
IGNORE=		Unknown TCL version specified: ${USE_TCL}
.endif
.endif # defined(USE_TCL)

.if defined(USE_TK)

_TK_VERSIONS=	84 83 82 81 80

.if ${USE_TK} == "yes"
USE_TK=		84
.endif

TK_VER:=	${USE_TK:S/8/8./}

.if defined(USE_TCL) && ${TCL_VER} != ${TK_VER}
IGNORE=		TCL and TK versions must be equal (${TCL_VER} vs ${TK_VER})
.endif

_FOUND=		no
.for ver in ${_TK_VERSIONS}
. if ${USE_TK} == ${ver}
_FOUND=		yes
RUN_DEPENDS+=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${USE_TK}
TCL_INCLUDEDIR=	${LOCALBASE}/include/tcl${TK_VER}
TCL_LIBDIR=		${LOCALBASE}/lib/tcl${TK_VER}
TK_INCLUDEDIR=	${LOCALBASE}/include/tk${TK_VER}
TK_LIBDIR=		${LOCALBASE}/lib/tk${TK_VER}
TCLSH=			${LOCALBASE}/bin/tclsh${TK_VER}
WISH=			${LOCALBASE}/bin/wish${TK_VER}
. endif
.endfor

.if ${_FOUND} == "no"
IGNORE=		Unknown TK version specified: ${USE_TK}
.endif
.endif # defined(USE_TK)

.endif # !defined(_POSTMKINCLUDED) && !defined(Tcl_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Tcl_Post_Include)

Tcl_Post_Include=	bsd.tcl.mk

.if defined(PATCH_TCL_SCRIPTS) || defined (PATCH_TK_SCRIPTS)
.if !target(post-patch)
post-patch:
.if defined(PATCH_TCL_SCRIPTS) && defined(TCLSH)
. for tcl_script in ${PATCH_TCL_SCRIPTS}
	@${REINPLACE_CMD} -e 's,tclsh,${TCLSH},' ${WRKSRC}/${tcl_script}
. endfor
.endif
.if defined(PATCH_TK_SCRIPTS) && defined(WISH)
. for tk_script in ${PATCH_TK_SCRIPTS}
	@${REINPLACE_CMD} -e 's,wish,${WISH},' ${WRKSRC}/${tk_script}
. endfor
.endif
.endif # !target(post-patch)
.endif # defined(PATCH_TCL_SCRIPTS) || defined (PATCH_TK_SCRIPTS)

.endif # defined(_POSTMKINCLUDED) && !defined(Tcl_Post_Include)
