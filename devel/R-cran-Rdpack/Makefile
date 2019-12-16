# $FreeBSD$

PORTNAME=	Rdpack
DISTVERSION=	0.11-1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Update and Manipulate Rd Documentation Objects

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-bibtex>=0.4.0:textproc/R-cran-bibtex \
		R-cran-gbRd>0:devel/R-cran-gbRd
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
