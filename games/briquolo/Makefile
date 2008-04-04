# New ports collection makefile for:  	briquolo
# Date created:       			18 Nov 2003
# Whom:  				Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	briquolo
PORTVERSION=	0.5.7
CATEGORIES=	games
MASTER_SITES=	http://briquolo.free.fr/download/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Breakout clone with an OpenGL 3D representation

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GL=		gl
USE_SDL=	mixer sdl ttf
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
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

pre-install:
	${MKDIR} ${PREFIX}/share/applications

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
