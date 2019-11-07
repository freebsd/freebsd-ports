# $FreeBSD$
#
# handle dependency on motif
#
# Feature:	motif
# Usage:	USES=motif
#
# If WANT_LESSTIF is defined in user make.conf then lesstif will be used
# instead of open-motif
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_MOTIF_MK)
_INCLUDE_USES_MOTIF_MK=	yes

.if !empty(motif_ARGS)
IGNORE=	USES=motif takes no arguments
.endif

.if defined(WANT_LESSTIF)
LIB_DEPENDS+=		libXm.so:x11-toolkits/lesstif
.else
USE_XORG+=	xpm
LIB_DEPENDS+=		libXm.so.4:x11-toolkits/open-motif
.endif

MOTIFLIB?=	-L${LOCALBASE}/lib -lXm
MAKE_ENV+=	MOTIFLIB="${MOTIFLIB}"

# We only need to include xorg.mk if we want USE_XORG modules
# USES+=xorg does not provide any functionality, it just silences an error
# message about USES=xorg not being set
.if defined(USE_XORG) && !empty(USE_XORG)
USES+=		xorg
.include "${USESDIR}/xorg.mk"
.endif

.endif
