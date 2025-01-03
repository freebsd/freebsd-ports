PORTNAME=	data.table
DISTVERSION=	1.16.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extension of Data.frame
WWW=		https://cran.r-project.org/web/packages/data.table/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-knitr>0:print/R-cran-knitr
# Tests fail if no /etc/locatime symlink defined

USES=		cran:auto-plist,compiles pkgconfig

EXTRA_PATCHES=	${FILESDIR}/extra-patch-test:-p1

NO_ARCH_IGNORE=	data_table.so

# Decompress so patch could be applied. Tests will run from uncompressed file.
pre-patch:
	${BZIP2_CMD} -d ${WRKSRC}/inst/tests/tests.Rraw.bz2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/data.table/libs/data_table.so

.include <bsd.port.mk>
