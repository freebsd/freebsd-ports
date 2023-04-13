PORTREVISION=	1
PKGNAMESUFFIX=	Compose

COMMENT?=	AppStream Compose application and library

LIB_DEPENDS=	libappstream.so:devel/appstream

USE_GNOME=	cairo gdkpixbuf2 librsvg2 pango

MESON_ARGS=	-Dcompose=true

MASTERDIR=	${.CURDIR}/../../devel/appstream
PLIST=		${.CURDIR}/pkg-plist

post-install:
	# remove files belonging to the master port
	${XARGS} -L 1 -I % ${RM} -rf ${STAGEDIR}${PREFIX}/% < ${MASTERDIR}/pkg-plist
	${FIND} ${STAGEDIR}${PREFIX} -empty -delete
	${RM} -rf ${STAGEDIR}${PREFIX}/etc ${STAGEDIR}${PREFIX}/man

.include	"${MASTERDIR}/Makefile"
