# Created by: xaa@stack.nl
# $FreeBSD$

PORTNAME=	xboard
PORTVERSION=	4.7.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo

OPTIONS_DEFINE=	NLS ZIPPY CRAFTY FAIRYMAX GNUCHESS KNIGHTCAP PHALANX DOCS
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes
ZIPPY_DESC=	Add Zippy capability (computer player on ICS)
CRAFTY_DESC=	Install crafty engine
FAIRYMAX_DESC=	Install fairymax engine
GNUCHESS_DESC=	Install GnuChess engine
KNIGHTCAP_DESC=	Install KnightCap engine
PHALANX_DESC=	Install phalanx engine
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
ZIPPY_CONFIGURE_ENABLE=	zippy
CRAFTY_RUN_DEPENDS+=	crafty:${PORTSDIR}/games/crafty
FAIRYMAX_RUN_DEPENDS+=	fairymax:${PORTSDIR}/games/fairymax
GNUCHESS_RUN_DEPENDS+=	gnuchess:${PORTSDIR}/games/gnuchess
KNIGHTCAP_RUN_DEPENDS+=	KnightCap:${PORTSDIR}/games/KnightCap
PHALANX_RUN_DEPENDS+=	phalanx:${PORTSDIR}/games/phalanx

USES=		desktop-file-utils makeinfo perl5 pkgconfig shared-mime-info
USE_XORG=	xt xpm xaw
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=MKDIR_P="${MKDIR}" PERLPATH=${LOCALBASE}/bin
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO=		xboard
USE_PERL5=	build
INSTALLS_ICONS=	yes
DATADIR=	${PREFIX}/share/games/${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog NEWS README SHORTLOG TODO

BROKEN_sparc64=	Does not install on sparc64

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZIPPY}
PORTDOCS+=	zippy.README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/fairymax/gnuchessx/' ${WRKSRC}/xboard.conf.in
	@${REINPLACE_CMD} -e '/^#include..malloc.h/d' \
		${WRKSRC}/engineoutput.c ${WRKSRC}/uci.c
	@${REINPLACE_CMD} -e 's:INSTALL.*sysconfdir):&/$$$$files.dist:' \
		${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MZIPPY}
	@cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/OPTION_ZIPPY__patch-xboard.texi
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' ${WRKSRC}/xboard.texi
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cmail ${STAGEDIR}${PREFIX}/bin/
	${MV} ${STAGEDIR}${PREFIX}/etc/xboard.conf.dist \
		 ${STAGEDIR}${PREFIX}/etc/xboard.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
