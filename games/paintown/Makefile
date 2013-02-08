# New ports collection makefile for:	paintown
# Date created:		2010-02-04
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	paintown
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Fighting game similar to Streets of Rage and TMNT

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	alleg.42:${PORTSDIR}/devel/allegro \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

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
		${MKDIR} ${DATADIR}
		(cd ${WRKSRC} && ./install.sh -d ${DATADIR} -b ${PREFIX}/bin)
		${MKDIR} ${LOCALBASE}/share/icons/hicolor/32x32/apps
		${INSTALL_DATA} ${WRKSRC}/misc/icon.png \
			${LOCALBASE}/share/icons/hicolor/32x32/apps/paintown.png

.include <bsd.port.mk>
