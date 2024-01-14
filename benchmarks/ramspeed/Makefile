PORTNAME=	ramspeed
PORTVERSION=	3.5.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.alasir.com/software/ramspeed/
DISTNAME=	ramsmp-${PORTVERSION}

MAINTAINER=	mkamm@gmx.net
COMMENT=	Cache and memory benchmarking tool
WWW=		http://alasir.com/software/ramspeed/

# do not sell for money
LICENSE=	ALASIR
LICENSE_NAME=	Alasir Licence
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell

BROKEN=		crashes upon execution, PR 275276
DEPRECATED=	Upstream is dead and port is unfetchable
EXPIRATION_DATE=2024-02-29

USE_BINUTILS=	yes

PLIST_FILES=	bin/ramspeed
PORTDOCS=	HISTORY README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ramsmp ${STAGEDIR}${PREFIX}/bin/ramspeed

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
