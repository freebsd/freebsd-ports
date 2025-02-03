PORTNAME=	brotli
DISTVERSION=	1.3.1
CATEGORIES=	archivers
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Compression Format Optimized for the Web
WWW=		https://CRAN.R-project.org/package=brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-microbenchmark>0:devel/R-cran-microbenchmark \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling
TESTING_UNSAFE=	R-cran-R.rsp is required

USES=		cran:auto-plist,compiles

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/brotli/bin/bro

.include <bsd.port.mk>
