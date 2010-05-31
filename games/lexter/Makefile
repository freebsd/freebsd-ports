# New ports collection makefile for:	lexter
# Date created:			Feb 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lexter
PORTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A real-time word puzzle for text terminals

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib'
CONFIGURE_ARGS+=	--localstatedir=/var/games
USE_GETTEXT=	yes

MAN6=	lexter.6

post-install:
	@${CHOWN} root:games ${PREFIX}/bin/lexter
	@${CHMOD} g+s ${PREFIX}/bin/lexter
	@${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
