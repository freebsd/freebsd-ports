# Common variables for KDevelop ports:
# devel/kdev-php
# devel/kdev-python
# devel/kdevelop

_kdevelop_PROJECT_VERSION=	6.3
PLATFORM_VER=	${_kdevelop_PROJECT_VERSION:S/.//}
PLIST_SUB+=	PLATFORM_VER="${PLATFORM_VER}"

PRIVATE_VER=	6.0
PLIST_SUB+=	PRIVATE_VER=${PRIVATE_VER}
