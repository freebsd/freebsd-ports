PORTNAME=	Rdpack
DISTVERSION=	2.1.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Update and Manipulate Rd Documentation Objects

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-gbRd>0:devel/R-cran-gbRd \
		R-cran-rbibutils>=1.3:textproc/R-cran-rbibutils
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
