# New ports collection makefile for:  	briquolo
# Date created:       			18 Nov 2003
# Whom:  				Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	briquolo
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://briquolo.free.fr/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Breakout clone with an OpenGL 3D representation

LIB_DEPENDS=	GUI.0:${PORTSDIR}/graphics/guilib \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_SDL=	mixer sdl

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} \
		${REINPLACE_CMD} -e 's|SDL/|SDL11/|g'
	@${FIND} ${WRKSRC} -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e 's|SDL/|SDL11/|g'

.include <bsd.port.post.mk>
