# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	ztcl
DISTVERSION=	1.0b4
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	http://download.gna.org/ztcl/1.0/
DISTNAME=	${PORTNAME}_${DISTVERSION}_src

MAINTAINER=	dsh@vlink.ru
COMMENT=	Zlib extension library for the Tcl

LICENSE=	LGPL21

LIB_DEPENDS=	libtclmore0.so:devel/tclmore

OPTIONS_DEFINE=	DOCS

USES=		gmake tcl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_src$//}

INFO=		${PORTNAME} ${PORTNAME}-zlib

CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tclmorescripts=${LOCALBASE}/libexec/tclmore \
		--enable-threads
MAKE_ENV+=	STAGEDIR=${STAGEDIR}
CPPFLAGS+=	-I ${LOCALBASE}/include -I ${TCL_INCLUDEDIR}
LDFLAGS+=	-L ${LOCALBASE}/lib

PORTDOCS=	*

post-extract:
	${MV} ${WRKSRC}/doc/zlib.texi ${WRKSRC}/doc/${PORTNAME}-zlib.texi

.include <bsd.port.mk>
