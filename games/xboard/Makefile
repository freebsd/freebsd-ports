# Created by: xaa@stack.nl
# $FreeBSD$

PORTNAME=	xboard
PORTVERSION=	4.7.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

OPTIONS_DEFINE=	NLS CRAFTY FAIRYMAX GNUCHESS KNIGHTCAP PHALANX
OPTIONS_DEFAULT=
CRAFTY_DESC=	Install crafty engine
FAIRYMAX_DESC=	Install fairymax engine
GNUCHESS_DESC=	Install GnuChess engine
KNIGHTCAP_DESC=	Install KnightCap engine
PHALANX_DESC=	Install phalanx engine

USES=		desktop-file-utils perl5 pkgconfig shared-mime-info
USE_XORG=	xt xpm xaw
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=MKDIR_P="${MKDIR}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN6=		xboard.6
INFO=		xboard
USE_PERL5=	build
INSTALLS_ICONS=	yes
DATADIR=	${PREFIX}/share/games/${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog NEWS README SHORTLOG TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRAFTY}
RUN_DEPENDS+=	crafty:${PORTSDIR}/games/crafty
.endif

.if ${PORT_OPTIONS:MFAIRYMAX}
RUN_DEPENDS+=	fairymax:${PORTSDIR}/games/fairymax
.endif

.if ${PORT_OPTIONS:MGNUCHESS}
RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
.endif

.if ${PORT_OPTIONS:MKNIGHTCAP}
RUN_DEPENDS+=	KnightCap:${PORTSDIR}/games/KnightCap
.endif

.if ${PORT_OPTIONS:MPHALANX}
RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not install on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/fairymax/gnuchessx/' ${WRKSRC}/xboard.conf.in
	@${REINPLACE_CMD} -e '/^#include..malloc.h/d' \
		${WRKSRC}/engineoutput.c ${WRKSRC}/uci.c
	@${REINPLACE_CMD} -e 's:INSTALL.*sysconfdir):&/$$$$files.dist:' \
		${WRKSRC}/Makefile.in

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/cmail ${PREFIX}/bin/
	@${CP} -pn ${PREFIX}/etc/xboard.conf.dist ${PREFIX}/etc/xboard.conf
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
