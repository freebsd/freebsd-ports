# Handle dependency on sudo
#
# Feature:	sudo
# Usage:	USES=sudo
#
# MAINTAINER: kiwi@FreeBSD.org

.if !defined(_INCLUDE_USES_SUDO_MK)
_INCLUDE_USES_SUDO_MK=   yes

SUDO_FLAVOR?=	${SUDO_DEFAULT}
SUDO_PORT?=	security/sudo
SUDO_DEPENDS=	${LOCALBASE}/bin/sudo:${SUDO_PORT}@${SUDO_FLAVOR}

RUN_DEPENDS+=	${SUDO_DEPENDS}
.endif
