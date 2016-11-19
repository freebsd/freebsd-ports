# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	the
PORTVERSION=	3.3.r4
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://downloads.sourceforge.net/hessling-editor/
DISTNAME=	THE-${PORTVERSION:S/.r/RC/}

MAINTAINER=	comet.berkeley@gmail.com
COMMENT=	THE, The Hessling Editor, is like the vm/cms xedit editor

LICENSE=	GPLv2

BROKEN_powerpc=	fails to configure

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rexxincdir=${LOCALBASE}/include \
		--with-rexxlibdir=${LOCALBASE}/lib
ALL_TARGET=	all html
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		XAW3D
OPTIONS_SINGLE=		Display Rexx
OPTIONS_SINGLE_Display=	NCURSES XCURSES
OPTIONS_SINGLE_Rexx=	REXX_IMC REGINA
OPTIONS_DEFAULT=	NCURSES REGINA
OPTIONS_SUB=		yes

XAW3D_DESC=		Enable Xaw3D
NCURSES_DESC=		Build standard NCurses version
XCURSES_DESC=		Build XCurses (X11) version
REXX_IMC_DESC=		Use Rexx/imc interpreter
REGINA_DESC=		Use Regina Rexx interpreter

XAW3D_CONFIGURE_WITH=	xaw3d
XAW3D_BUILD_DEPENDS=	${LOCALBASE}/lib/libXaw3d.a:x11-toolkits/Xaw3d

NCURSES_USES=		ncurses
NCURSES_CONFIGURE_ON=	--with-ncurses \
			--with-cursesincdir=${NCURSESINC} \
			--with-curseslibdir=${NCURSESLIB}

XCURSES_LIB_DEPENDS=	libXCurses.so:devel/pdcurses
XCURSES_CONFIGURE_ON=	--with-xcurses \
			--with-cursesincdir=${LOCALBASE}/include \
			--with-curseslibdir=${LOCALBASE}/lib
XCURSES_CFLAGS=		-I${LOCALBASE}/include \
			-I${LOCALBASE}/include/xcurses

REXX_IMC_CONFIGURE_ON=	--with-rexx=rexximc
REXX_IMC_BUILD_DEPENDS=	rexx:lang/rexx-imc
REXX_IMC_RUN_DEPENDS=	rexx:lang/rexx-imc
REXX_IMC_BROKEN=	fails to build with REXX_IMC option

REGINA_CONFIGURE_ON=	--with-rexx=regina
REGINA_BUILD_DEPENDS=	regina:lang/rexx-regina
REGINA_RUN_DEPENDS=	regina:lang/rexx-regina

post-extract:
	${REINPLACE_CMD} -e 's|(datadir)/THE|(datadir)/the|g' \
			-e 's|/share/THE|/share/the|g' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|ltermcap|lncurses|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e '/FUNCTION_KEY/d' ${WRKSRC}/the.c

pre-install:
	${MKDIR}				${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/the64.gif    	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/the64.png	${STAGEDIR}${DOCSDIR}

do-install-XCURSES-on:
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/xthe
	${LN} -sf xthe 	${STAGEDIR}${PREFIX}/bin/the

do-install-NCURSES-on:
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/nthe
	${LN} -sf nthe 	${STAGEDIR}${PREFIX}/bin/the

.include <bsd.port.mk>
