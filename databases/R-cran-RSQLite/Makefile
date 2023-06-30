PORTNAME=	RSQLite
PORTVERSION=	2.2.19
PORTREVISION=	1
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Database Interface R driver for SQLite
WWW=		https://cran.r-project.org/web/packages/RSQLite/

LICENSE=	LGPL20

CRAN_DEPENDS=	R-cran-DBI>=1.1.0:databases/R-cran-DBI \
		R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-blob>0:devel/R-cran-blob \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-plogr>0:devel/R-cran-plogr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|PKG_CPPFLAGS=|PKG_CPPFLAGS=-Wno-error=enum-constexpr-conversion |g' \
		${WRKSRC}/src/Makevars
.endif

.include <bsd.port.mk>
