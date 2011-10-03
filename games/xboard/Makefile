# New ports collection makefile for:    xboard
# Date created:         5 Jan 1997
# Whom:                 xaa@stack.nl
#
# $FreeBSD$
#

PORTNAME=	xboard
PORTVERSION=	4.5.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xboard

MAINTAINER=	johans@FreeBSD.org
COMMENT=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

OPTIONS=	XAW3D		"Use Xaw3d widgets (instead of Xaw)"	On \
		CRAFTY		"Install crafty engine"			Off \
		FAIRYMAX	"Install fairymax engine"		Off \
		GNUCHESS	"Install GnuChess engine"		Off \
		KNIGHTCAP	"Install KnightCap engine"		Off \
		PHALANX		"Install phalanx engine"		Off

USE_XORG=	xt xpm xaw
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=CFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		MKDIR_P="${MKDIR}"
MAN6=		xboard.6
INFO=		xboard
USE_PERL5_BUILD=yes
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

.ifdef	WITH_XAW3D
CONFIGURE_ARGS+=	"--with-Xaw3d"
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

.ifdef WITH_CRAFTY
RUN_DEPENDS+=	crafty:${PORTSDIR}/games/crafty
.endif

.ifdef WITH_FAIRYMAX
RUN_DEPENDS+=	fairymax:${PORTSDIR}/games/fairymax
.endif

.ifdef WITH_GNUCHESS
RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.ifdef WITH_KNIGHTCAP
RUN_DEPENDS+=	KnightCap:${PORTSDIR}/games/KnightCap
.endif

.ifdef WITH_PHALANX
RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not install on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/fairymax/gnuchessx/' \
		${WRKSRC}/xboard.h ${WRKSRC}/xboard.conf.in
	@${REINPLACE_CMD} -e '/^#include..malloc.h/d' \
		${WRKSRC}/engineoutput.c ${WRKSRC}/uci.c
	@${REINPLACE_CMD} -e 's:INSTALL.*sysconfdir):&/$$$$files.dist:' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/^SendString/void &/' ${WRKSRC}/xoptions.c

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/cmail ${PREFIX}/bin/
	@${CP} -pn ${PREFIX}/etc/xboard.conf.dist ${PREFIX}/etc/xboard.conf

.include <bsd.port.post.mk>
