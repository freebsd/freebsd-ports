# New ports collection makefile for:    xboard
# Date created:         5 Jan 1997
# Whom:                 xaa@stack.nl
#
# $FreeBSD$
#

PORTNAME=	xboard
PORTVERSION=	4.2.7
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.tim-mann.org/xboard/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xboard

MAINTAINER=	johans@stack.nl
COMMENT=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

USE_XORG=	xt xpm xaw
GNU_CONFIGURE=	yes
STRIP=
MAN6=		xboard.6 zic2xpm.6
INFO=		xboard
USE_PERL5_BUILD=yes

.if defined(WITH_XAW3D)
CONFIGURE_ARGS+=	"--with-Xaw3d"
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,$$(prefix)/share/info,@infodir@,' \
		-e 's, html dvi ps,,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
