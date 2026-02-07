PKGNAMEPREFIX=
PKGNAMESUFFIX=	-common

COMMENT=	Common files for Python bindings for GObject Introspection

NO_BUILD=	yes
NO_TEST=	yes
NO_ARCH=	yes
PLIST_FILES=	include/pygobject-3.0/pygobject.h \
		libdata/pkgconfig/pygobject-3.0.pc

SLAVE_PORT=	common

MASTERDIR=	${.CURDIR}/../../devel/py-pygobject

.include "${MASTERDIR}/Makefile"
