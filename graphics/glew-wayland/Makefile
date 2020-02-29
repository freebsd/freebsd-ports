# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-wayland

# https://github.com/nigels-com/glew/issues/172
MAINTAINER=	jbeich@FreeBSD.org

MASTERDIR=	${.CURDIR}/../glew
PLIST=		${.CURDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

USE_GL=		gl egl
USE_XORG=	# empty
MAKE_ARGS=	NAME=${PORTNAME:tu}${PKGNAMESUFFIX}
INSTALL_TARGET=	install.lib

OPTIONS_DEFINE=	# empty

post-patch:	slave-post-patch
slave-post-patch:
	@${REINPLACE_CMD} 's/Makefile.$$(SYSTEM)/&-egl/' ${WRKSRC}/Makefile
	@${SED} 's/linux/${OPSYS:tl}/' ${WRKSRC}/config/Makefile.linux-egl \
		>${WRKSRC}/config/Makefile.${OPSYS:tl}-egl
	@${REINPLACE_CMD} -e '/^Requires:/d' \
		-e '/^Name:/s/${PORTNAME}/${PKGBASE}/' \
		${WRKSRC}/${PORTNAME}.pc.in
# GCC 4.2 doesn't support redefining same typedef
	@${REINPLACE_CMD} '/typedef.*EGLint;/d' ${WRKSRC}/include/GL/eglew.h

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/glewinfo \
		${STAGEDIR}${PREFIX}/bin/glewinfo${PKGNAMESUFFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/visualinfo \
		${STAGEDIR}${PREFIX}/bin/visualinfo${PKGNAMESUFFIX}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/eglew.h \
		${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/${PKGBASE}.pc

.include "${MASTERDIR}/Makefile"
