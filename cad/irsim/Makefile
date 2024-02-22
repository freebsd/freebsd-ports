PORTNAME=	irsim
DISTVERSION=	9.7.116
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/irsim/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Event-driven logic-level simulator for MOS circuis
WWW=		http://opencircuitdesign.com/irsim/

LICENSE=	GPLv2

USES=	gmake tar:tgz xorg

OPTIONS_RADIO=	INTERPRETER
OPTIONS_RADIO_INTERPRETER=	SCHEME TCL
OPTIONS_DEFAULT=	SCHEME
SCHEME_DESC=	Scheme interpreter
TCL_DESC=	Tcl interpreter
OPTIONS_SUB=	yes

SCHEME_CONFIGURE_ON=	--with-interpreter=scheme
TCL_CONFIGURE_ON=	--with-interpreter=tcl
TCL_USES=		tk:tea

CONFIGURE_WRKSRC=	${WRKSRC}/scripts

USE_XORG=	x11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
PLIST_SUB+=	NOTCL="@comment "
.else
WISH=		${FALSE}
PLIST_SUB+=	NOTCL=""
.endif

.if empty(PORT_OPTIONS:MSCHEME) && empty(PORT_OPTIONS:MTCL)
CONFIGURE_ARGS+=	--with-interpreter=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|FreeBSD-\*|*-*-freebsd*| ; \
		 s|wish |${WISH:T} | ; \
		 s|"-fpic"|"-fPIC"| ; \
		 /-l\/usr\/X11R6\/include/d' ${CONFIGURE_WRKSRC}/configure

post-install:
.if empty(PORT_OPTIONS:MTCL)
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/gentbl bin/genspktbl bin/irsim
.else
	cd ${STAGEDIR}${PREFIX}/lib/irsim/tcl && \
		${STRIP_CMD} irsimexec tclirsim.so diglib.so random.so
.endif

.include <bsd.port.mk>
