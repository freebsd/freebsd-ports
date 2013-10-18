# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sea-defender
PORTVERSION=	r20100723
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple missile command clone

BUILD_DEPENDS=	${LOCALBASE}/lib/libglfw.a:${PORTSDIR}/graphics/glfw

USE_BZIP2=	yes
USES=		gmake
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
USE_XORG=	x11 xrandr

SUB_FILES=	${PORTNAME}.sh
PLIST_FILES=	libexec/${PORTNAME} bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README

DESKTOP_ENTRIES="Sea Defender" \
		"${COMMENT}" \
		"" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${FILESDIR}/extra-snoutlib_gldefs.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sea ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
