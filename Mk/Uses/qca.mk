# $FreeBSD$
#
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

_QCA_LIB=		libqca-qt5.so

_QCA_DEFAULT_PORT=	devel/qca
_QCA_LEGACY_PORT=	devel/qca-legacy

.  if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200085 && ${SSL_DEFAULT} == base
_QCA_CHOSEN_PORT=	LEGACY
.  else
_QCA_CHOSEN_PORT=	DEFAULT
.  endif

LIB_DEPENDS+=		${_QCA_LIB}:${_QCA_${_QCA_CHOSEN_PORT}_PORT}

.endif
