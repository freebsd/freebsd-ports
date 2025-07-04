PORTNAME=	jujutsu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0
CATEGORIES=	devel

MAINTAINER=	se@FreeBSD.org
COMMENT=	Git-compatible VCS that is both simple and powerful
WWW=		https://jj-vcs.github.io/jj/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo localbase shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	jj-vcs
GH_PROJECT=	jj

SHEBANG_FILES=	demos/*.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/target/release/jj \
			${STAGEDIR}${PREFIX}/bin/
		cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
		cd ${WRKSRC}/demos && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
