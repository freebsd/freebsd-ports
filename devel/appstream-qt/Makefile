PORTREVISION=	0
PKGNAMESUFFIX=	Qt6

COMMENT=	Qt bindings to AppStream

LIB_DEPENDS=	libappstream.so:devel/appstream

USES=		qt:6
USE_QT=		base

MESON_ARGS=	-Dqt=true

MASTERDIR=	${.CURDIR}/../appstream
PLIST=		${.CURDIR}/pkg-plist

post-install:
	# remove files belonging to the master port
	${XARGS} -L 1 -I % ${RM} -rf ${STAGEDIR}${PREFIX}/% < ${MASTERDIR}/pkg-plist
	${FIND} ${STAGEDIR}${PREFIX} -empty -delete
	${RM} -rf ${STAGEDIR}${PREFIX}/etc ${STAGEDIR}${PREFIX}/share/man

.include	"${MASTERDIR}/Makefile"
