PORTREVISION=	1
PKGNAMESUFFIX=	Qt

COMMENT?=	Qt bindings to AppStream

LIB_DEPENDS=	libappstream.so:devel/appstream

USES=		qt:5

USE_QT=		core buildtools:build qmake:build testlib:build

MESON_ARGS=	-Dqt5=true

MASTERDIR=	${.CURDIR}/../appstream
PLIST=		${.CURDIR}/pkg-plist

post-install:
	# remove files belonging to the master port
	${XARGS} -L 1 -I % ${RM} -rf ${STAGEDIR}${PREFIX}/% < ${MASTERDIR}/pkg-plist
	${FIND} ${STAGEDIR}${PREFIX} -empty -delete
	${RM} -rf ${STAGEDIR}${PREFIX}/etc ${STAGEDIR}${PREFIX}/man

.include	"${MASTERDIR}/Makefile"
