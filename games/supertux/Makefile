# New ports collection makefile for:	supertux
# Date created:		2004-04-17
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	supertux
PORTVERSION=	0.0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	super-tux

MAINTAINER=	ahze@ahze.net
COMMENT=	Super Tux is a side-scroller similar to Super Mario Brothers

USE_X_PREFIX=	yes
USE_BZIP2=	yes
WANT_SDL=	yes
USE_SDL=	image
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--disable-debug
OPTIONS=		SOUND "SDL mixer (audio) support" on
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=--disable-sound
.else
USE_SDL+=	mixer
PLIST_SUB+=	SOUND=""
.endif

post-patch:
.if defined(WITHOUT_SOUND)
	@${RM} -f ${WRKSRC}/data/sounds/* ${WRKSRC}/data/music/*
.endif
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' \
		${WRKSRC}/src/type.h

.include <bsd.port.post.mk>
