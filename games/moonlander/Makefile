# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	moonlander
PORTVERSION=	1.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	DEBIAN/pool/main/m/moon-lander
DISTNAME=	moon-lander_${PORTVERSION}.orig

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Land a spacecraft on the moon

LICENSE=	BSD2CLAUSE

USE_SDL=	mixer image sdl

WRKSRC=		${WRKDIR}/moon-lander

SOUNDS=		sounds

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

OPTIONS_DEFINE=	SOUND
OPTIONS_DEFAULT=SOUND

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSOUND}
SOUNDS=		# empty
CFLAGS+=	-DNOSOUND
.endif

do-configure:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/moon_lander.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moonlander ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "fonts images ${SOUNDS}" ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
