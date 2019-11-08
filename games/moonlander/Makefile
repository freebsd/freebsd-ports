# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	moonlander
PORTVERSION=	1.0
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	DEBIAN/pool/main/m/moon-lander
DISTNAME=	moon-lander_${PORTVERSION}.orig

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Land a spacecraft on the moon

LICENSE=	BSD2CLAUSE

USES=		sdl
USE_SDL=	mixer image sdl

WRKSRC=		${WRKDIR}/moon-lander

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

OPTIONS_DEFINE=	SOUND
OPTIONS_DEFAULT=SOUND

SOUND_CFLAGS_OFF=	-DNOSOUND

do-configure:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/moon_lander.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moonlander ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "fonts images" ${STAGEDIR}${DATADIR}/

post-install-SOUND-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} sounds ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
