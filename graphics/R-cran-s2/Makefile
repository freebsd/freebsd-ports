PORTNAME=	s2
PORTVERSION=	1.0.6
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Spherical Geometry Operators Using the S2 Geometry Library

LICENSE=	APACHE20

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

CRAN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-wk>0:math/R-cran-wk
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
