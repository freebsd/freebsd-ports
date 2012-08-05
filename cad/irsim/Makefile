# New ports collection makefile for:    irsim
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	irsim
PORTVERSION=	9.7.74
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/irsim/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An event-driven logic-level simulator for MOS circuis

LICENSE=	GPLv2

OPTIONS_DEFINE=	INTERPRETER
OPTIONS_SINGLE=	INTERPRETER
OPTIONS_SINGLE_INTERPRETER=	SCHEME TCL
OPTIONS_DEFAULT=	INTERPRETER SCHEME
INTERPRETER_DESC=	Enable built-in interpreter support
SCHEME_DESC=	Scheme interpreter
TCL_DESC=	Tcl interpreter

CONFIGURE_WRKSRC=	${WRKSRC}/scripts

USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		irsim.1
MAN3=		irsim-analyzer.3
MAN5=		netchange.5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
USE_TK_BUILD=	yes
USE_TK=		yes
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR} \
			--with-tclincls=${TCL_INCLUDEDIR} \
			--with-tkincls=${TK_INCLUDEDIR} \
			--with-tcllibs=${LOCALBASE}/lib \
			--with-tklibs=${LOCALBASE}/lib \
			--with-interpreter=tcl
PLIST_SUB+=	TCL="" NOTCL="@comment "
.else
WISH=		${FALSE}
PLIST_SUB+=	TCL="@comment " NOTCL=""
.endif

.if ${PORT_OPTIONS:MSCHEME}
CONFIGURE_ARGS+=	--with-interpreter=scheme
.endif

.if empty(PORT_OPTIONS:MSCHEME) && empty(PORT_OPTIONS:MTCL)
CONFIGURE_ARGS+=	--with-interpreter=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|FreeBSD-\*|*-*-freebsd*| ; \
		 s|wish |${WISH:T} | ; \
		 s|-lpthread|${PTHREAD_LIBS}| ; \
		 s|"-fpic"|"-fPIC"| ; \
		 /-l\/usr\/X11R6\/include/d' ${CONFIGURE_WRKSRC}/configure

.include <bsd.port.mk>
