# New ports collection makefile for:    irsim
# Date created:         18 Dec 1994
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	irsim
PORTVERSION=	9.7.72
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/irsim/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An event-driven logic-level simulator for MOS circuis

USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/scripts/

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	PIC_CFLAGS="-fpic" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OPTIONS_SINGLE=	INTERPRETER
OPTIONS_SINGLE_INTERPRETER=	TCL SCHEME
OPTIONS_DEFAULT=	SCHEME
SCHEME_DESC=	Enable built-in Scheme interpreter
TCL_DESC=	Enable built-in Tcl interpreter

MAN1=		irsim.1
MAN3=		irsim-analyzer.3
MAN5=		netchange.5

TK_VER=		8.4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
LIB_DEPENDS+=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl${TK_VER} \
			--with-tk=${LOCALBASE}/lib/tk${TK_VER} \
			--with-tcllibs=${LOCALBASE}/lib/ \
			--with-tklibs=${LOCALBASE}/lib/ \
			--with-tclincls=${LOCALBASE}/include/tcl${TK_VER} \
			--with-tkincls=${LOCALBASE}/include/tk${TK_VER} \
			--with-interpreter=tcl
PLIST_SUB+=	TCL=""
.else
PLIST_SUB+=	TCL="@comment "
.endif

.if ${PORT_OPTIONS:MSCHEME}
CONFIGURE_ARGS+=	--with-interpreter=scheme
PLIST_SUB+=	SCHEME=""
.else
PLIST_SUB+=	SCHEME="@comment "
.endif

.include <bsd.port.mk>
