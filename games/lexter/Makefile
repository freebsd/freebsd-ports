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

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games

USE_GMAKE=	yes

MAN6=	lexter.6

.include <bsd.port.mk>
