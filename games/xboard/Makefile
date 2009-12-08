# New ports collection makefile for:    xboard
# Date created:         5 Jan 1997
# Whom:                 xaa@stack.nl
#
# $FreeBSD$
#

PORTNAME=	xboard
PORTVERSION=	4.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xboard

MAINTAINER=	johans@stack.nl
COMMENT=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

OPTIONS=	XAW3D	"Use Xaw3d widgets (instead of Xaw)"	On

USE_XORG=	xt xpm xaw
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"
MAN6=		xboard.6
INFO=		xboard
USE_PERL5_BUILD=yes
PLIST_FILES=	bin/xboard bin/cmail

.include <bsd.port.options.mk>

.ifdef	WITH_XAW3D
CONFIGURE_ARGS+=	"--with-Xaw3d"
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

post-patch:
		@${REINPLACE_CMD} -e 's/fairymax/gnuchessx/' ${WRKSRC}/xboard.h

post-install:
		@${INSTALL_SCRIPT} ${WRKSRC}/cmail ${PREFIX}/bin/

.include <bsd.port.post.mk>
