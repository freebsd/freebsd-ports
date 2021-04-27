PORTNAME=	ramspeed
PORTVERSION=	3.5.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.alasir.com/software/ramspeed/
DISTNAME=	ramsmp-${PORTVERSION}

MAINTAINER=	mkamm@gmx.net
COMMENT=	Cache and memory benchmarking tool

# do not sell for money
LICENSE=	ALASIR
LICENSE_NAME=	Alasir Licence
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell

PLIST_FILES=	bin/ramspeed
PORTDOCS=	HISTORY README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ramsmp ${STAGEDIR}${PREFIX}/bin/ramspeed
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
