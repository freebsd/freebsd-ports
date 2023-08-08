PORTNAME=	cccc
DISTVERSION=	3.2.0
CATEGORIES=	devel textproc www

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	C and C++ Code Counter
WWW=		http://cccc.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/cccc/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	sarnold

PORTSCOUT=	limit:^[0-9].*$$

MAKE_ENV=	CCC="${CXX}" LD="${CXX}" CFLAGS_DEBUG="${CXXFLAGS}"
ALL_TARGET=	cccc
MAKE_JOBS_UNSAFE=	yes
PORTDOCS=	README.md CHANGELOG.md
PLIST_FILES=	bin/cccc

OPTIONS_DEFINE=	DOCS DEBUG

DEBUG_MAKE_ENV=	DEBUG="true"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cccc/cccc ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
