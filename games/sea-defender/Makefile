# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sea-defender
PORTVERSION=	0.9
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/:icon \
		SF/nemysisfreebsdp/:icon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icon
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple missile command clone

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/lib/libglfw.a:graphics/glfw2

USE_GITHUB=	yes
GH_ACCOUNT=	snoutmate
GH_PROJECT=	Sea-Defender
GH_TAGNAME=	d628051

USES=		gmake
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
USE_XORG=	x11 xrandr

SUB_FILES=	${PORTNAME}.sh
PLIST_FILES=	bin/${PORTNAME} \
		libexec/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	*

DESKTOP_ENTRIES="Sea Defender" \
		"${COMMENT}" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/typedef/ d' ${WRKSRC}/snoutlib/gldefs.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sea ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
