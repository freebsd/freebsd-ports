# $FreeBSD$

PORTNAME=	allegro
DISTVERSION=	4.4.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform library for games and multimedia programming

USE_GMAKE=	yes
USES=		cmake pkgconfig
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_LDCONFIG=	yes
WANT_GNOME=	yes
USE_GL=		gl glu

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

CONFLICTS=	allegro-devel-[0-9]*
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}"

SHLIB_VER=	4.4.2

PORTSCOUT=	limit:^4\.3\.[0-9]*

CFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib \
		jack.0:${PORTSDIR}/audio/jack \
		png15:${PORTSDIR}/graphics/png

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
.include "Makefile.man"
INFO=		allegro
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	 @${REINPLACE_CMD} -e 's|add_subdirectory(docs)|#add_subdirectory(docs)|' ${WRKSRC}/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs/man/ && \
		${FIND} . -type f -and -name "*.3" -exec ${INSTALL_MAN} {} ${PREFIX}/man/man3/{} \;
.endif

.include <bsd.port.mk>
