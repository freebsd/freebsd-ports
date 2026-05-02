PORTNAME=	bear
DISTVERSION=	4.1.2
CATEGORIES=	devel

MAINTAINER=	aokblast@FreeBSD.org
COMMENT=	Tool that generates a compilation database for clang tooling
WWW=		https://github.com/rizsotto/Bear

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	rizsotto
GH_PROJECT=	Bear

OPTIONS_DEFINE=	DOCS

do-install:
	${WRKDIR}/target/release/generate-completions ${WRKDIR}/target/release/completions
	${SETENV} DESTDIR=${STAGEDIR} PREFIX=${PREFIX} SRCDIR=${WRKDIR}/target/release ${WRKSRC}/scripts/install.sh

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CODE_OF_CONDUCT.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CONTRIBUTING.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE.md ${STAGEDIR}${DOCSDIR}

post-install:
.for l in libexec/bear/bin/bear-driver libexec/bear/bin/bear-wrapper libexec/bear/lib/libexec.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${l}
.endfor

.include <bsd.port.mk>
