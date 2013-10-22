# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	briquolo
PORTVERSION=	0.5.7
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://briquolo.free.fr/download/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Breakout clone with an OpenGL 3D representation

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		iconv
USE_GL=		gl
USE_SDL=	mixer sdl ttf
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

#.if defined(WITHOUT_NLS)
#BROKEN=	Unsupported: wants to link against libintl anyway
#CONFIGURE_ARGS+=	--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.else
USES+=		gettext
PLIST_SUB+=	NLS=""
#.endif

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|png_infopp_NULL|NULL|g' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/src/MOGL/MOGL_Image.cpp

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
