# New ports collection makefile for:	ztcl
# Date created:				Tue Apr 25 17:49:31 MSD 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	ztcl
DISTVERSION=	1.0b4
CATEGORIES=	devel tcl84
MASTER_SITES=	http://download.gna.org/ztcl/1.0/
DISTNAME=	${PORTNAME}_${DISTVERSION}_src

MAINTAINER=	dsh@vlink.ru
COMMENT=	A zlib extension library for the Tcl

LIB_DEPENDS=	tclmore0.7:${PORTSDIR}/devel/tclmore
# USE_TCL only gives run dependency
BUILD_DEPENDS=	${RUN_DEPENDS}

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_TCL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_src$//}

INFO=		${PORTNAME} ${PORTNAME}-zlib

CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tclmorescripts=${PREFIX}/libexec/tclmore
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I ${PREFIX}/include -I ${TCL_INCLUDEDIR}" \
		LDFLAGS="${LDFLAGS} -L ${PREFIX}/lib"
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS} -I ${PREFIX}/include -I ${TCL_INCLUDEDIR}" \
		LDFLAGS="${LDFLAGS} -L ${PREFIX}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.X
.endif

post-extract:
	${MV} ${WRKSRC}/doc/zlib.texi ${WRKSRC}/doc/${PORTNAME}-zlib.texi

.include <bsd.port.post.mk>
