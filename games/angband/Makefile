# New ports collection makefile for:   angband
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	angband
PORTVERSION=	3.0.8
CATEGORIES=	games
MASTER_SITES=	http://rephial.org/downloads/ \
		http://angband.oook.cz/download/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Rogue-like game with color, X11 support

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-setgid=games
.if !defined(WITHOUT_X11)
USE_XORG=	sm x11
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--with-x=no
.endif

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-fetch:
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "You could define WITHOUT_X11, if you don't want X support"
.else
	@${ECHO_MSG} "Building without X support"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lSM|-L${LOCALBASE}/lib -lSM|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| $$(INCLUDEDIR)||' ${WRKSRC}/mk/objective.mk

post-configure:
	@${REINPLACE_CMD} -e 's|$${prefix}|${PREFIX}|' ${WRKSRC}/src/autoconf.h

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
