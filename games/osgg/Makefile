# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osgg
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OldSkool Gravity Game

LICENSE=	GPLv3+

BROKEN=		unfetchable (checksum mismatch)

USES=		tar:bzip2
USE_SDL=	sdl image ttf mixer
USE_GL=		gl
MAKE_ENV=	DATADIR="${DATADIR}/"

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="Osgg" \
		"" \
		"${DATADIR}/icon.png" \
		"osgg" \
		"Game;ArcadeGame;" \
		""

post-extract:
	@${RM} -f ${WRKSRC}/osgg ${WRKSRC}/launcher/launcher

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.txt *.ogg Bandal.ttf icon.png levels" ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
