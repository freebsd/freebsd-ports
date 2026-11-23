PORTNAME=	watcher
DISTVERSION=	0.2.2
CATEGORIES=	filesystems sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Watch the file system for changes
WWW=		https://watcher.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfswatch.so:filesystems/fswatch-mon
RUN_DEPENDS=	R-cran-later>0:devel/R-cran-later \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rlang>0:devel/R-cran-rlang

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
