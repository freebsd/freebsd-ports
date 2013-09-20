# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	ztcl
DISTVERSION=	1.0b4
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	http://download.gna.org/ztcl/1.0/
DISTNAME=	${PORTNAME}_${DISTVERSION}_src

MAINTAINER=	dsh@vlink.ru
COMMENT=	A zlib extension library for the Tcl

LIB_DEPENDS=	tclmore0.7:${PORTSDIR}/devel/tclmore

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_TCL=	yes
USE_TCL_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_src$//}

INFO=		${PORTNAME} ${PORTNAME}-zlib

CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tclmorescripts=${PREFIX}/libexec/tclmore
CPPFLAGS+=	-I ${PREFIX}/include -I ${TCL_INCLUDEDIR}
LDFLAGS+=	-L ${PREFIX}/lib

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
post-extract:
	${MV} ${WRKSRC}/doc/zlib.texi ${WRKSRC}/doc/${PORTNAME}-zlib.texi

.include <bsd.port.mk>
