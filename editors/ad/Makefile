PORTNAME=	ad
DISTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	editors

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Adaptable text editor
WWW=		https://crates.io/crates/ad-editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sminez

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/ad.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)
	${RM} -r ${STAGEDIR}${DOCSDIR}/man

.include <bsd.port.mk>
