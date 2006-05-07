# New ports collection makefile for:    xboard
# Date created:         5 Jan 1997
# Whom:                 xaa@stack.nl
#
# $FreeBSD$
#

PORTNAME=	xboard
PORTVERSION=	4.2.7
CATEGORIES=	games
MASTER_SITES=	http://www.tim-mann.org/xboard/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xboard

MAINTAINER=	xaa+ports@timewasters.nl
COMMENT=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html

USE_XLIB=	yes
GNU_CONFIGURE=	yes
STRIP=
MAN6=		xboard.6 zic2xpm.6
INFO=		xboard

.if defined(WITH_XAW3D)
CONFIGURE_ARGS+=	"--with-Xaw3d"
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,$$(prefix)/share/info,@infodir@,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
