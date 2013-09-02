# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-demos
PORTVERSION=	8.1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/${PORTVERSION}/
DISTFILES=	mesa-demos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

USE_BZIP2=	yes
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GL=		glu glut glew
USE_XORG=	glproto x11 xext xi xxf86vm xdamage xfixes dri2proto
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	NVIDIA
NVIDIA_DESC=	Use NVIDIA's libraries

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math|${FAST_MATH}|' -e 's|x86_64|amd64|' \
		${WRKSRC}/configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
CFLAGS+=	-DWITH_NVIDIA_GL=1
.endif

.include <bsd.port.mk>
