# New ports collection makefile for:	moonlander
# Date created:				27 Jun 2003
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moonlander
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://downloads.daveblood.com/lunar_lander/
DISTNAME=	moon-lander-1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"land a spacecraft on the moon"

USE_SDL=	mixer image sdl
USE_X_PREFIX=	YES
USE_REINPLACE=	YES

WRKSRC=		${WRKDIR}/moon-lander

OPTIONS=	SOUND "Sound support" on

.include <bsd.port.pre.mk>

install_dirs=	fonts images
.if defined(WITHOUT_SOUND)
CFLAGS+=	-DNOSOUND
PLIST_SUB+=	SOUND="@comment "
.else
PLIST_SUB+=	SOUND=
install_dirs+=	sounds
.endif

do-configure:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/moon_lander.c

do-install:
	@${MKDIR} ${PREFIX}/bin; \
	${INSTALL_PROGRAM} ${WRKSRC}/moonlander ${PREFIX}/bin; \
	${MKDIR} ${PREFIX}/share/moonlander
.for i in ${install_dirs}
	@cp -R ${WRKSRC}/${i} ${PREFIX}/share/moonlander
.endfor

post-install:
	@${FIND} ${PREFIX}/share/moonlander -type f -print0 | \
		${XARGS} -0 ${CHMOD} 444

.include <bsd.port.post.mk>
