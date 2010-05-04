# New ports collection makefile for:   angband
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	angband
DISTVERSION=	3.1.2v2
CATEGORIES=	games
MASTER_SITES=	http://rephial.org/downloads/3.1/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Rogue-like game with color, X11 support

USE_GMAKE=	yes
ALL_TARGET=	#
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-setgid=games --disable-sdl --disable-sdl-mixer --with-varpath=/var/games/angband
.if !defined(WITHOUT_X11)
USE_XORG=	sm x11
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--with-x=no
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
CONFIGURE_ENV=	ac_cv_path_mkdir=mkdir

SUB_FILES=	pkg-message

pre-fetch:
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "You could define WITHOUT_X11, if you don't want X support"
.else
	@${ECHO_MSG} "Building without X support"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers ||' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
