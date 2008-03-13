# New ports collection makefile for:   angband
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	angband
PORTVERSION=	3.0.9a
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://rephial.org/downloads/3.0/ \
		http://angband.oook.cz/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Rogue-like game with color, X11 support

USE_GMAKE=	yes
ALL_TARGET=	#
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-setgid=games --disable-sdl --disable-sdl-mixer
.if !defined(WITHOUT_X11)
USE_XORG=	sm x11
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--with-x=no
.endif

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-fetch:
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "You could define WITHOUT_X11, if you don't want X support"
.else
	@${ECHO_MSG} "Building without X support"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| $$(INCLUDEDIR)||' ${WRKSRC}/mk/objective.mk
	@${REINPLACE_CMD} -e 's|;$$|; \\|' ${WRKSRC}/src/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
