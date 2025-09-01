PORTNAME=	cpu_rec_rs
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.0.0
PORTREVISION=	19
CATEGORIES=	devel

PATCH_SITES=	https://github.com/trou/${PORTNAME}/commit/
PATCHFILES=	2b0cf547ce1eaa4b153c812f51bb9ab6928784cd.patch:-p1

MAINTAINER=	se@FreeBSD.org
COMMENT=	Determine which CPU architecture is used in a binary file
WWW=		https://github.com/trou/cpu_rec_rs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	trou

OPTIONS_DEFINE=	DOCS

pre-build:
		${REINPLACE_CMD} 's!%%CORPUS_DIR%%!${DATADIR}!' ${WRKSRC}/src/main.rs

pre-install:
		${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/cpu_rec_corpus/*.corpus ${STAGEDIR}${DATADIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
