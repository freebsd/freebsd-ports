PORTREVISION=	0
PKGNAMESUFFIX=	Compose

COMMENT?=	AppStream Compose application and library

LIB_DEPENDS=	libappstream.so:devel/appstream \
		libfyaml.so:textproc/libfyaml
RUN_DEPENDS=	optipng:graphics/optipng \
		ffprobe:multimedia/ffmpeg

USE_GNOME=	cairo gdkpixbuf librsvg2 pango

MESON_ARGS=	-Dcompose=true

MASTERDIR=	${.CURDIR}/../../devel/appstream
PLIST=		${.CURDIR}/pkg-plist

post-install:
	# remove files belonging to the master port
	${XARGS} -L 1 -I % ${RM} -rf ${STAGEDIR}${PREFIX}/% < ${MASTERDIR}/pkg-plist
	${FIND} ${STAGEDIR}${PREFIX} -empty -delete
	${RM} -rf ${STAGEDIR}${PREFIX}/etc ${STAGEDIR}${PREFIX}/share/man

.include	"${MASTERDIR}/Makefile"
