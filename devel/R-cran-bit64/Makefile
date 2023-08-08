PORTNAME=	bit64
DISTVERSION=	4.0.5
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	S3 Class for Vectors of 64bit Integers
WWW=		https://cran.r-project.org/web/packages/bit64/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-bit>=4.0.0:devel/R-cran-bit
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
