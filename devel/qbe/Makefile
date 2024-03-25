PORTNAME=	qbe
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	https://c9x.me/git/qbe.git/release//

MAINTAINER=	se@FreeBSD.org
COMMENT=	Embeddable compiler backend for C type languages
WWW=		https://c9x.me/compile/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake tar:xz

TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

do-build:
		cd ${WRKSRC}; ${GMAKE} CC=cc

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/qbe ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
