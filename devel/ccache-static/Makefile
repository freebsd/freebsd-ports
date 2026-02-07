PKGNAMESUFFIX=	-static

MASTERDIR=	${.CURDIR}/../ccache

OPTIONS_SLAVE=	STATIC

CONFLICTS_INSTALL=	ccache ccache-memcached ccache-memcached-static

PIE_UNSAFE=	yes

.include "${MASTERDIR}/Makefile"
