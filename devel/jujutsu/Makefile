PORTNAME=	jujutsu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.43.0
CATEGORIES=	devel

MAINTAINER=	se@FreeBSD.org
COMMENT=	Git-compatible VCS that is both simple and powerful
WWW=		https://docs.jj-vcs.dev/v${DISTVERSION}/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		cargo localbase shebangfix
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
		cd ${TMPDIR:U/tmp} && ${STAGEDIR}${PREFIX}/bin/jj util install-man-pages ${STAGEDIR}${PREFIX}/share/man/
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
		cd ${TMPDIR:U/tmp} && ${STAGEDIR}${PREFIX}/bin/jj util completion bash > ${STAGEDIR}${PREFIX}/etc/bash_completion.d/jj
		${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
		cd ${TMPDIR:U/tmp} && ${STAGEDIR}${PREFIX}/bin/jj util completion zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_jj

.include <bsd.port.mk>
