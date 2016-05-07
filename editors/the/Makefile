# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	the
PORTVERSION=	3.3.r4
CATEGORIES=	editors
MASTER_SITES=	http://downloads.sourceforge.net/hessling-editor/
DISTNAME=	THE-${PORTVERSION:S/.r/RC/}

MAINTAINER=	comet.berkeley@gmail.com
COMMENT=	THE, The Hessling Editor, is like the vm/cms xedit editor

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses \
		--with-rexxincdir=${LOCALBASE}/include \
		--with-rexxlibdir=${LOCALBASE}/lib
ALL_TARGET=	all html

OPTIONS_DEFINE=	XAW3D XCURSES REXX_IMC
XAW3D_DESC=	Enable Xaw3D
XCURSES_DESC=	Build XCurses (X11) version
REXX_REGINA_DESC=	Enable Rexx interpreter

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

.if ${PORT_OPTIONS:MXAW3D}
CONFIGURE_ARGS+=--with-xaw3d
LIB_DEPENDS+=	libxaw3d.so:x11-toolkits/Xaw3d
.endif

.if ${PORT_OPTIONS:MXCURSES}
CONFIGURE_ARGS+=--with-xcurses \
		--with-cursesincdir=${LOCALBASE}/include \
		--with-curseslibdir=${LOCALBASE}/lib
BUILD_DEPENDS+=	pdcurses:devel/pdcurses
LIB_DEPENDS+=	libxcurses.so:devel/pdcurses
PLIST_SUB=	XCURSES="" NCURSES="@comment "
.else
PLIST_SUB=	XCURSES="@comment " NCURSES=""
.endif

.if ${PORT_OPTIONS:MREXX_IMC}
BUILD_DEPENDS+=	rexx:lang/rexx-imc
RUN_DEPENDS+=	rexx:lang/rexx-imc
CONFIGURE_ARGS+=	--with-rexx=rexximc
.else
BUILD_DEPENDS+=	regina:lang/rexx-regina
RUN_DEPENDS+=	regina:lang/rexx-regina
CONFIGURE_ARGS+=	--with-rexx=regina
.endif

post-extract:
	${REINPLACE_CMD} -e 's|(datadir)/THE|(datadir)/the|g' \
			-e 's|/share/THE|/share/the|g'	 ${WRKSRC}/Makefile.in

pre-install:
	${MKDIR}				${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/the64.gif    	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/the64.png	${STAGEDIR}${DOCSDIR}

post-install:
.if ${PORT_OPTIONS:MXCURSES}
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/xthe
	${LN} -sf xthe 	${STAGEDIR}${PREFIX}/bin/the
.else
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/nthe
	${LN} -sf nthe 	${STAGEDIR}${PREFIX}/bin/the
.endif

.include <bsd.port.post.mk>
