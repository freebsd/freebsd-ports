# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osgg
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OldSkool Gravity Game

LICENSE=	GPLv3+

USE_GITHUB=	yes
GH_ACCOUNT=	DusteDdk
GH_PROJECT=	Osgg
GH_TAGNAME=	32d9e02 # 1.0 + extra FreeBSD-related fixes

USES=		gl sdl xorg
USE_SDL=	sdl image ttf mixer
USE_GL=		gl
MAKE_ENV=	DATADIR="${DATADIR}/"

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*.txt *.ogg Bandal.ttf icon.png levels

DESKTOP_ENTRIES="Osgg" \
		"" \
		"${DATADIR}/icon.png" \
		"osgg" \
		"Game;ArcadeGame;" \
		""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
