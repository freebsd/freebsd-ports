# $FreeBSD$

PORTREVISION=	0
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

.include "${MASTERDIR}/Makefile"
