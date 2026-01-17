PORTNAME=	bear
DISTVERSION=	4.0.1
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
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/bear ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/wrapper ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/libexec.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/bear.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AGENTS.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CODE_OF_CONDUCT.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CONTRIBUTING.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install:
.for l in bin/bear lib/${PORTNAME}/libexec.so lib/${PORTNAME}/wrapper
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${l}
.endfor

.include <bsd.port.mk>
