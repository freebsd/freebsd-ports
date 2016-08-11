# $FreeBSD$
#
# Changes some default behaviour of build systems to allow installing as user.
#
# Feature:	uidfix
# Usage:	USES=uidfix
# Valid ARGS:	none
#
# MAINTAINER:	bapt@FreeBSD.org

.if !defined(_INCLUDE_USES_UIDFIX_MK)
_INCLUDE_USES_UIDFIX_MK=	yes
.if !defined(GID)
GID!=	id -g
.endif
.if ${UID} != 0
MAKE_ENV+=	BINOWN=${UID} SHAREOWN=${UID} CONFOWN=${UID} LIBOWN=${UID}
MAKE_ENV+=	BINGRP=${GID} SHAREGRP=${GID} CONFGRP=${GID} LIBGRP=${GID}
MAKE_ENV+=	INCSOWN=${UID} INCSGRP=${GID}
BINOWN=	${UID}
LIBOWN=	${UID}
SHAREOWN=	${UID}
WWWOWN=	${UID}
BINGRP=	${GID}
LIBGRP=	${GID}
SHAREGRP=	${GID}
WWWGRP=	${GID}
INCSOWN=	${UID}
INCSGRP=	${GID}
.endif
.endif
