PORTNAME=	libdistance
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~jose/software/libdistance/

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Compute the distance between two pieces of data
WWW=		https://monkey.org/~jose/software/libdistance

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	swig:devel/swig

USES+=		fakeroot pkgconfig tcl
USE_LDCONFIG=	yes

MAKE_ARGS+=	INCLUDEDIR=${PREFIX}/include LIBDIR=${PREFIX}/lib
MAKE_ARGS+=	MANDIR=${PREFIX}/man/man SWIG=swig
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-fPIC

.include <bsd.port.options.mk>

.if defined(NOPROFILE) || defined(NO_PROFILE) || ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079 )
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-patch:
	${REINPLACE_CMD} 's|%%TCL_SHLIB_VER%%|${TCL_SHLIB_VER}|' \
	    ${WRKSRC}/swig/tcl/Makefile

pre-build:
	${MKDIR} ${STAGEDIR}${PREFIX}/tests/${PORTNAME}

.include <bsd.port.mk>
