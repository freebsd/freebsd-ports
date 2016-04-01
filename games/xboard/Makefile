# Created by: xaa@stack.nl
# $FreeBSD$

PORTNAME?=	xboard
PORTVERSION?=	4.8.0
PORTREVISION?=	0
PORTEPOCH?=
CATEGORIES?=	games
MASTER_SITES?=	GNU

MAINTAINER?=	johans@FreeBSD.org
COMMENT?=	X frontend for Crafty, GNUChess, Chess Servers, or e-mail chess

LICENSE?=	GPLv3

LIB_DEPENDS?=	libcairo.so:graphics/cairo

CONFLICTS?=	xboard-devel-[0-9]*

OPTIONS_DEFINE?=	NLS DOCS ZIPPY
OPTIONS_SINGLE?=	FRONTEND
OPTIONS_SINGLE_FRONTEND?=	XAW XAW3D GTK2
OPTIONS_GROUP?=	ENGINES
OPTIONS_GROUP_ENGINES?=	FAIRYMAX CRAFTY GNUCHESS KNIGHTCAP PHALANX
OPTIONS_RADIO?=	SOUND
OPTIONS_RADIO_SOUND?=	SOX ALSA
OPTIONS_DEFAULT?=	XAW
OPTIONS_SUB?=	yes
ZIPPY_DESC=	Add Zippy capability (computer player on ICS)
ENGINES_DESC=	Chess Engines
CRAFTY_DESC=	Install crafty engine
FAIRYMAX_DESC=	Install fairymax engine (many chess variants)
GNUCHESS_DESC=	Install GnuChess engine
KNIGHTCAP_DESC=	Install KnightCap engine
PHALANX_DESC=	Install phalanx engine
FRONTEND_DESC=	Front End
XAW_DESC=	Xaw GUI toolkit support (default)
XAW3D_DESC=	Xaw3d GUI toolkit support (not fully supported)
GTK2_DESC=	GTK+ 2 GUI toolkit support (experimental)
SOUND_DESC=	Sound Output (optional)
SOX_DESC=	SoX audio support
CRAFTY_RUN_DEPENDS+=	crafty:games/crafty
FAIRYMAX_RUN_DEPENDS+=	fairymax:games/fairymax
GNUCHESS_RUN_DEPENDS+=	gnuchess:games/gnuchess
KNIGHTCAP_RUN_DEPENDS+=	KnightCap:games/KnightCap
PHALANX_RUN_DEPENDS+=	phalanx:games/phalanx
XAW3D_DEPENDS+=	libXaw3d.so:x11-toolkits/Xaw3d
SOX_RUN_DEPENDS+=	play:audio/sox
ALSA_RUN_DEPENDS+=	aplay:audio/alsa-utils
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
ZIPPY_CONFIGURE_ENABLE=	zippy
XAW_CONFIGURE_WITH=	Xaw
XAW3D_CONFIGURE_WITH=	Xaw3d
GTK2_CONFIGURE_WITH=	gtk

.include <bsd.port.options.mk>

USES+=		desktop-file-utils makeinfo perl5 pkgconfig shared-mime-info \
		shebangfix
USE_XORG+=	xt xpm
USE_GNOME+=	librsvg2
.if ${PORT_OPTIONS:MXAW}
USE_XORG+=	xaw
.endif
.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
.endif
SHEBANG_FILES=	texi2man

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=MKDIR_P="${MKDIR}" PERLPATH=${PERL}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO=		xboard
USE_PERL5=	build
INSTALLS_ICONS=	yes
DATADIR?=	${PREFIX}/share/games/${PORTNAME}
XBOARDCONF?=	${WRKSRC}/xboard.conf

PORTDOCS=	AUTHORS COPYING COPYRIGHT ChangeLog DIFFSTAT FAQ.html NEWS README SHORTLOG TODO

BROKEN_sparc64=	Does not install on sparc64

.if ${PORT_OPTIONS:MZIPPY}
USES+=		shebangfix
SHEBANG_FILES+=	./texi2man
PORTDOCS+=	zippy.README
.endif

.if ${PORT_OPTIONS:MNLS}
PORTDOCS+=	ABOUT-NLS
.endif

post-patch:
	-@[ -f ${WRKSRC}/Makefile.in ] && ${REINPLACE_CMD} -e \
		'/xboard_LDADD/s/-ldl //' ${WRKSRC}/Makefile.in
	@${ECHO_CMD} -n "" > ${WRKSRC}/engineEntries.txt
	@${ECHO_CMD} -n "" > ${WRKSRC}/firstEngine.txt
.if ${PORT_OPTIONS:MCRAFTY}
	@${ECHO_CMD} "\"Crafty\" -fcp crafty\\" >> ${WRKSRC}/engineEntries.txt
	@${ECHO_CMD} -n "crafty" > ${WRKSRC}/firstEngine.txt
.endif
.if ${PORT_OPTIONS:MGNUCHESS}
	@${ECHO_CMD} "\"GNU Chess\" -fcp gnuchess\\" >> ${WRKSRC}/engineEntries.txt
	@${ECHO_CMD} -n "gnuchess" > ${WRKSRC}/firstEngine.txt
.endif
.if ${PORT_OPTIONS:MKNIGHTCAP}
	@${ECHO_CMD} "\"KnightCap\" -fcp \"KnightCap -n -X -A -f ${PREFIX}/share/games/KnightCap/coeffs.dat\"\\" >> ${WRKSRC}/engineEntries.txt
	@${ECHO_CMD} -n "KnightCap" > ${WRKSRC}/firstEngine.txt
.endif
.if ${PORT_OPTIONS:MPHALANX}
	@${ECHO_CMD} "\"Phalanx\" -fcp phalanx\\" >> ${WRKSRC}/engineEntries.txt
	@${ECHO_CMD} -n "phalanx" > ${WRKSRC}/firstEngine.txt
.endif
.if ${PORT_OPTIONS:MFAIRYMAX}
	@${ECHO_CMD} "\"FairyMax\" -fcp fairymax\\" >> ${WRKSRC}/engineEntries.txt
	@${ECHO_CMD} -n "fairymax" > ${WRKSRC}/firstEngine.txt
.endif
	@firstEngine=`cat ${WRKSRC}/firstEngine.txt` && \
	 ${REINPLACE_CMD} -e "s|\(-firstChessProgram\) .*|\1 $${firstEngine}|" ${XBOARDCONF}
	@engineEntries=`cat ${WRKSRC}/engineEntries.txt` && \
	 ${REINPLACE_CMD} -e "s|\(firstChessProgramNames[ 	]*{\)[ 	]*.*|\1$${engineEntries}}|" ${XBOARDCONF}
	@${REINPLACE_CMD} -e '/^#include..malloc.h/d' \
		${WRKSRC}/engineoutput.c ${WRKSRC}/uci.c
.if ${PORT_OPTIONS:MZIPPY}
	@cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/OPTION_ZIPPY__patch-xboard.texi
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' ${WRKSRC}/xboard.texi
.endif
.if ${PORT_OPTIONS:MSOX}
	@${REINPLACE_CMD} -e "s|\(soundProgram\) .*|\1 \"play -q\"|" ${XBOARDCONF}
.elif ${PORT_OPTIONS:MALSA}
	@${REINPLACE_CMD} -e "s|\(soundProgram\) .*|\1 \"aplay -q\"|" ${XBOARDCONF}
.else
	@${REINPLACE_CMD} -e "s|\(soundProgram\) .*|\1 \"\"|" ${XBOARDCONF}
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cmail ${STAGEDIR}${PREFIX}/bin/
	${MV} ${STAGEDIR}${PREFIX}/etc/xboard.conf \
		 ${STAGEDIR}${PREFIX}/etc/xboard.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
