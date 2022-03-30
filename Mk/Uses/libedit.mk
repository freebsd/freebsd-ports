# handle dependency on the libedit port
#
# Feature:	libedit
# Usage:	USES=libedit
# Valid ARGS:	none
#
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_LIBEDIT_MK)
_INCLUDE_USES_LIBEDIT_MK=	yes
_USES_POST+=	localbase

LIB_DEPENDS+=	libedit.so.0:devel/libedit
.endif
