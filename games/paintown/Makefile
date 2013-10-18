# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	paintown
PORTVERSION=	3.6.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Fighting game similar to Streets of Rage and TMNT

LICENSE=	BSD

LIB_DEPENDS=	liballeg.so:${PORTSDIR}/devel/allegro \
		libpng.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_SCONS=	yes
USE_SDL=	yes
INSTALLS_ICONS=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)

SCONS_BUILDENV+=CPPPATH="${LOCALBASE}/include" \
		LIBPATH="${LOCALBASE}/lib"

DESKTOP_ENTRIES="Paintown" "Fighting game similar to Streets of Rage and TMNT" \
		"${LOCALBASE}/share/icons/hicolor/32x32/apps/paintown.png" \
		"paintown" "Game;ActionGame;" false

do-install:
		${MKDIR} ${STAGEDIR}${DATADIR}
		(cd ${WRKSRC} && ./install.sh -d ${STAGEDIR}${DATADIR} -b ${STAGEDIR}${PREFIX}/bin)
		${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/32x32/apps
		${INSTALL_DATA} ${WRKSRC}/misc/icon.png \
			${STAGEDIR}${LOCALBASE}/share/icons/hicolor/32x32/apps/paintown.png

.include <bsd.port.mk>
