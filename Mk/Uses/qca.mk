# Handle dependency on qca
#
# Feature:		qca
# Usage:		USES=qca
# Valid ARGS		none
#
# MAINTAINER:		kde@FreeBSD.org

.if ! defined(_INCLUDE_QCA_MK)
_INCLUDE_QCA_MK=	yes

.  if !empty(qca_ARGS)
IGNORE+=		USES=qca takes no arguments
.  endif

.  if empty(USES:Mqt*)
IGNORE+=		Qt version not specified
.  endif

_QCA_LIB=		libqca-qt${_QT_VER}.so

_QCA_DEFAULT_PORT=	devel/qca
_QCA_CHOSEN_PORT=	DEFAULT
_QCA_FLAVOR=		qt${_QT_VER}

LIB_DEPENDS+=		${_QCA_LIB}:${_QCA_${_QCA_CHOSEN_PORT}_PORT}@${_QCA_FLAVOR}

.endif
