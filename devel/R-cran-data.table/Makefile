PORTNAME=	data.table
DISTVERSION=	1.14.10
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extension of Data.frame
WWW=		https://cran.r-project.org/web/packages/data.table/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cran:auto-plist,compiles pkgconfig

NO_ARCH_IGNORE=	data_table.so

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_CONFIGURE_ENABLE=	openmp

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
USE_GCC=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/data.table/libs/data_table.so

.include <bsd.port.mk>
