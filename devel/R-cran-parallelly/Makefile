PORTNAME=	parallelly
DISTVERSION=	1.45.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Enhancing the 'parallel' Package
WWW=		https://cran.r-project.org/package=parallelly

LICENSE=	LGPL21+

USES=		cran:auto-plist,compiles

NO_ARCH_IGNORE=	parallelly.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/parallelly/libs/parallelly.so

.include <bsd.port.mk>
