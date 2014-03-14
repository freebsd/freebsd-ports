# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	briquolo
PORTVERSION=	0.5.7
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://briquolo.free.fr/download/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Breakout clone with an OpenGL 3D representation

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		desktop-file-utils gmake iconv
USE_BZIP2=	yes
USE_GL=		gl
USE_SDL=	mixer sdl ttf
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

# Mandatory: wants to link against libintl anyway
USES+=		gettext
PLIST_SUB+=	NLS=""

post-patch:
	${REINPLACE_CMD} -e 's|png_infopp_NULL|NULL|g' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/src/MOGL/MOGL_Image.cpp

.include <bsd.port.mk>
