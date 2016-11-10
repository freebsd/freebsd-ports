# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	paintown
PORTVERSION=	3.6.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fighting game similar to Streets of Rage and TMNT

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liballeg.so:devel/allegro \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		dos2unix scons tar:bzip2
USE_SDL=	yes
INSTALLS_ICONS=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)

DESKTOP_ENTRIES="Paintown" "" \
		"${LOCALBASE}/share/icons/hicolor/32x32/apps/paintown.png" \
		"paintown" "Game;ActionGame;" false

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ./install.sh -d ${DATADIR} -b ${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/misc/icon.png \
		${STAGEDIR}${LOCALBASE}/share/icons/hicolor/32x32/apps/paintown.png
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/paintown/paintown-bin

.include <bsd.port.mk>
