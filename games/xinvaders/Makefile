# New ports collection makefile for:    xinvaders
# Date created:         3 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xinvaders
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade/invaders

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shoot-em-up them nasty little bugs

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

ONLY_FOR_ARCHS=	i386

NO_CDROM=	"don't sell for profit"

USE_X_PREFIX=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--include-deps
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--enable-scorefile=${PREFIX}/share/xinvaders/xinvaders.scores

MAN6=		xinvaders.6

post-install:
	${INSTALL_DATA} ${FILESDIR}/Vaders.ad ${PREFIX}/lib/X11/app-defaults/Vaders
	@${MKDIR} ${PREFIX}/share/xinvaders
	@${ECHO_CMD} '0' > ${PREFIX}/share/xinvaders/xinvaders.scores
	@${CHOWN} root:games ${PREFIX}/bin/xinvaders
	@${CHMOD} 2555 ${PREFIX}/bin/xinvaders
	@${CHOWN} root:games ${PREFIX}/share/xinvaders/xinvaders.scores
	@${CHMOD} 0660 ${PREFIX}/share/xinvaders/xinvaders.scores

.include <bsd.port.mk>
