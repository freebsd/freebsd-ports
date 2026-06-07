PORTNAME=	data.table
DISTVERSION=	1.18.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extension of Data.frame
WWW=		https://cran.r-project.org/package=data.table

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-R.utils>0:devel/R-cran-R.utils

USES=		cran:auto-plist,compiles pkgconfig

NO_ARCH_IGNORE=	data_table.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/data.table/libs/data_table.so

.include <bsd.port.mk>
