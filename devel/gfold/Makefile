PORTNAME=	gfold
DISTVERSION=	4.0.0
PORTREVISION=	30
CATEGORIES=	devel

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	CLI tool to help keep track of your Git repositories
WWW=		https://github.com/nickgerace/gfold

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	nickgerace
BINARY_NAME=	gitfold

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

PORTDOCS=	CHANGELOG.md README.md
PLIST_FILES=	bin/${BINARY_NAME}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${BINARY_NAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include "${.CURDIR}/bsd.gfold.mk"
.include <bsd.port.mk>
