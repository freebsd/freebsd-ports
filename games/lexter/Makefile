# ex:ts=8
# New ports collection makefile for:	lexter
# Date created:			Feb 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lexter
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	mark@kyne.com.au

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib'
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share/lexter

MAN6=	lexter.6

post-install:
	@${CHOWN} root.games ${PREFIX}/bin/lexter
	@${CHMOD} g+s ${PREFIX}/bin/lexter
	@${TRUE} > ${PREFIX}/share/lexter/lexter.scores
	@${CHOWN} root.games ${PREFIX}/share/lexter/lexter.scores
	@${CHMOD} 664 ${PREFIX}/share/lexter/lexter.scores

.include <bsd.port.mk>
