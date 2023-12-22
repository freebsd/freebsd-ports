PORTNAME=	s2
PORTVERSION=	1.1.6
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Spherical Geometry Operators Using the S2 Geometry Library
WWW=		https://cran.r-project.org/web/packages/s2/

LICENSE=	APACHE20

NOT_FOR_ARCHS=	armv6 mips
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

CRAN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-wk>=0.6.0:math/R-cran-wk
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_Makevars.in
.endif

.include <bsd.port.mk>
