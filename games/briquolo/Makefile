# New ports collection makefile for:  	briquolo
# Date created:       			18 Nov 2003
# Whom:  				Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	briquolo
PORTVERSION=	0.5.7
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://briquolo.free.fr/download/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Breakout clone with an OpenGL 3D representation

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GL=		gl
USE_SDL=	mixer sdl ttf
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="${PORTVERSION}"

#.if defined(WITHOUT_NLS)
#BROKEN=	"Unsupported: wants to link against libintl anyway"
#CONFIGURE_ARGS+=	--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
#.endif

post-patch:
	${REINPLACE_CMD} -e 's|png_infopp_NULL|NULL|g' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/src/MOGL/MOGL_Image.cpp

pre-install:
	${MKDIR} ${PREFIX}/share/applications

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
