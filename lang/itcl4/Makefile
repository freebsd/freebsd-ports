PORTNAME=	itcl4
DISTVERSION=	4.3.4
CATEGORIES=	lang
MASTER_SITES=	SF/tcl/Tcl/8.6.17
DISTNAME=	itcl${DISTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Object-oriented extension to Tcl [incr Tcl]
WWW=		https://core.tcl.tk/itcl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.terms

USES=		tcl:86+,tea

CONFIGURE_ARGS+=--includedir=${PREFIX}/include/itcl${DISTVERSION:R}
PLIST_SUB+=	PKGVER=${DISTVERSION} \
		SHORT_PKGVER=${DISTVERSION:R}
TEST_TARGET=	test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/itcl${DISTVERSION}/lib${TCL_PKG_LIB_PREFIX}itcl${DISTVERSION}.so

.include <bsd.port.mk>
