PKGNAMESUFFIX=	35-tools

COMMENT=	Game integrated development environment

BROKEN=		Fails to build, error: no member named 'u' in 'QuadraticBezierCurve<V>'
DEPRECATED=	Fails to build and legacy, consider migrating to devel/godot-tools
EXPIRATION_DATE=2025-07-31

OPTIONS_EXCLUDE=	#
OPTIONS_SLAVE=	TOOLS
# we don't want the pkg-message from the master port
PKGMESSAGE=

MASTERDIR=	${.CURDIR}/../godot35

.include "${MASTERDIR}/Makefile"
