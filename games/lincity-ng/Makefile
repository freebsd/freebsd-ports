# Created by: Andrej Zverev
# $FreeBSD$

PORTNAME=	lincity-ng
PORTVERSION=	2.0
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	BERLIOS

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Improved rich city simulation game for X

BUILD_DEPENDS=	jam:devel/jam
LIB_DEPENDS=	libphysfs.so:devel/physfs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gnome localbase:ldflags pkgconfig sdl tar:bzip2 xorg
USE_SDL=	sdl mixer image ttf gfx
USE_GL=		gl
USE_XORG=	x11
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libphysfs=${LOCALBASE} \
		--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
LDFLAGS+=	-lpthread

PLIST_FILES=	bin/lincity-ng \
		share/applications/lincity-ng.desktop \
		share/pixmaps/lincity-ng.png
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| -O| -I${LOCALBASE}/include&|g' \
		${WRKSRC}/Jamrules

do-build:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} jam -dx -j${MAKE_JOBS_NUMBER})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} jam -dx -sprefix=${PREFIX} -sDESTDIR=${STAGEDIR} ${INSTALL_TARGET})

.include <bsd.port.mk>
