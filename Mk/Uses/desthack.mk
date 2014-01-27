#
# $FreeBSD$
#
# Handle gnu configure that does not properly support DESTDIR
#
# MAINTAINER:	portmgr@FreeBSD.org
#
# Feature:	desthack
# Usage:	USES=desthack
# Valide ARGS:	none
#

.if !defined(_INCLUDE_USES_DESTHACK_MK)
_INCLUDE_USES_DESTHACK_MK=	yes

.if defined(_desthack_ARGS)
IGNORE=	USES=desthack does not require args
.endif

_USES_POST=	desthack
GNU_CONFIGURE_PREFIX=	\$${${DESTDIRNAME}}${PREFIX}
GNU_CONFIGURE_MANPREFIX=	\$${${DESTDIRNAME}}${MANPREFIX}
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_DESTHACK_POST_MK)
_INCLUDE_USES_DESTHACK_POST_MK=	yes
post-stage:
	@${SED} -i '' -e 's,${STAGEDIR},,g' ${STAGEDIR}${PREFIX}/lib/*.la
.endif
