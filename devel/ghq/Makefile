PORTNAME=	ghq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Repository management tool (Git, Hg, SVN, Fossil, Bazaar, Darcs)
WWW=		https://github.com/x-motemen/ghq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	git>0:devel/git

USES=		go:modules

GO_MODULE=	github.com/x-motemen/ghq

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

post-build-MANPAGES-on:
	cd ${WRKSRC} && asciidoctor -b manpage -d manpage -o ghq.1 README.adoc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/misc/bash/_ghq \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_ghq \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/ghq.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
