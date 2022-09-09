# Sets the default variables to handle metaports
#
# Feature:	metaport
# Usage:	USES=metaport
#
# Take no arguments

.if !defined(_INCLUDE_USES_METAPORT_MK)
_INCLUDE_USES_METAPORT_MK=	yes

LICENSE=	NA
LICENSE_NAME=	Non applicable
LICENSE_TEXT=	No licenses are applicable to metaports
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
MASTER_SITES=	#
DISTFILES=	#
EXTRACT_ONLY=	#
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes
NO_ARCH=	yes

.endif
