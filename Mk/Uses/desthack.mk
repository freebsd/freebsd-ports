#
# $FreeBSD$
#
# Handle gnu configure that does not properly support DESTDIR
#
# MAINTAINER:	portmgr@FreeBSD.org
#
# Feature:	desthack
# Usage:	USES=desthack
# Valid ARGS:	none
#

.if !defined(_INCLUDE_USES_DESTHACK_MK)
_INCLUDE_USES_DESTHACK_MK=	yes

.if defined(_desthack_ARGS)
IGNORE=	USES=desthack valid args are none or 'la'
.endif

GNU_CONFIGURE_PREFIX=	\$${${DESTDIRNAME}}${PREFIX}
GNU_CONFIGURE_MANPREFIX=	\$${${DESTDIRNAME}}${MANPREFIX}
.endif
