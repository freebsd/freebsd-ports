PORTNAME=	fansi
DISTVERSION=	1.0.7
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	ANSI Control Sequence Aware String Functions
WWW=		https://cran.r-project.org/package=fansi

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cran:auto-plist,compiles

TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

.include <bsd.port.mk>
