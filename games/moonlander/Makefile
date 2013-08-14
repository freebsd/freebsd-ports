# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	moonlander
PORTVERSION=	1.0
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=pool/main/m/moon-lander
DISTNAME=	moon-lander_1.0.orig

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Land a spacecraft on the moon

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/README.txt

USE_SDL=	mixer image sdl

WRKSRC=		${WRKDIR}/moon-lander

OPTIONS_DEFINE=	SOUND

.include <bsd.port.options.mk>

install_dirs=	fonts images
.if ${PORT_OPTIONS:MSOUND}
PLIST_SUB+=	SOUND=
install_dirs+=	sounds
.else
CFLAGS+=	-DNOSOUND
PLIST_SUB+=	SOUND="@comment "
.endif

do-configure:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/moon_lander.c

do-install:
	@${MKDIR} ${PREFIX}/bin; \
	${INSTALL_PROGRAM} ${WRKSRC}/moonlander ${PREFIX}/bin; \
	${MKDIR} ${DATADIR}
.for i in ${install_dirs}
	@${CP} -R ${WRKSRC}/${i} ${DATADIR}
.endfor

post-install:
	@${FIND} ${PREFIX}/share/moonlander -type f -print0 | \
		${XARGS} -0 ${CHMOD} 444

.include <bsd.port.mk>
