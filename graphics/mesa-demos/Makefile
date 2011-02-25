# New ports collection makefile for:    mesa-demos
# Date created:         7 Nov 2003
# Whom:                 anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	demos
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics
MASTER_SITES=	CRITICAL/mesa3d:mesa,glut,demos
PKGNAMEPREFIX=	mesa-

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	OpenGL demos distributed with Mesa

USE_GL=		glu glut
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS=	NVIDIA_GL	"Use NVIDIA's libraries"	off

EXTRA_PATCHES+=	${FILESDIR}/patch-progs-xdemos-glxpixmap.c \
		${FILESDIR}/patch-progs-xdemos-yuvrect_client.c


do-install:
	@for i in demos xdemos; do \
		cd ${WRKSRC}/progs/$$i; \
		for j in `${MAKE} -V PROGS`; do \
			${ECHO_CMD} ${INSTALL_PROGRAM} $$j ${PREFIX}/bin; \
			${INSTALL_PROGRAM} $$j ${PREFIX}/bin; \
		done; \
	done
	${MKDIR} ${DATADIR}/images ${DATADIR}/data
	@cd ${WRKSRC}/progs/images; \
		for i in `ls *.rgb*`; do \
			${ECHO_CMD} ${INSTALL_DATA} $$i ${DATADIR}/images; \
			${INSTALL_DATA} $$i ${DATADIR}/images; \
		done
	@cd ${WRKSRC}/progs/demos; \
		for i in `ls *.dat`; do \
			${ECHO_CMD} ${INSTALL_DATA} $$i ${DATADIR}/data; \
			${INSTALL_DATA} $$i ${DATADIR}/data; \
		done

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.pre.mk>
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

.if defined(WITH_NVIDIA_GL)
CFLAGS+=	-DWITH_NVIDIA_GL=1
.endif

.include <bsd.port.post.mk>
