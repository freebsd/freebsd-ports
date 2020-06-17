# $FreeBSD$

PORTNAME=	libdistance
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~jose/software/libdistance/

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Compute the distance between two pieces of data

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	swig:devel/swig

USES+=		fakeroot pkgconfig tcl
USE_LDCONFIG=	yes

MAKE_ARGS+=	INCLUDEDIR=${PREFIX}/include LIBDIR=${PREFIX}/lib
MAKE_ARGS+=	MANDIR=${PREFIX}/man/man SWIG=swig
CFLAGS+=	-fPIC

pre-build:
	mkdir -p ${STAGEDIR}/usr/local/tests/${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's|%%TCL_SHLIB_VER%%|${TCL_SHLIB_VER}|' \
	    ${WRKSRC}/swig/tcl/Makefile

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
