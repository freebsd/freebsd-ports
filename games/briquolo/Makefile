# New ports collection makefile for:  	briquolo
# Date created:       			18 Nov 2003
# Whom:  				Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	briquolo
PORTVERSION=	0.5.4
CATEGORIES=	games
MASTER_SITES=	http://briquolo.free.fr/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Breakout clone with an OpenGL 3D representation

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_ICONV=	yes
USE_SDL=	mixer sdl ttf
USE_GCC=	3.4
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_SUB=	VERSION="${PORTVERSION}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'

pre-install:
	${MKDIR} ${PREFIX}/share/applications

.include <bsd.port.mk>
