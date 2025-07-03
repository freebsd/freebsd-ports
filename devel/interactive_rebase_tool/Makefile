PORTNAME=	interactive_rebase_tool
DISTVERSION=	2.4.1
PORTREVISION=	12
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Improved sequence editor for Git
WWW=		https://gitrebasetool.mitmaro.ca/

LICENSE=	GPLv3+

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	MitMaro
GH_PROJECT=	git-interactive-rebase-tool

PLIST_FILES=	bin/interactive-rebase-tool \
		share/man/man1/interactive-rebase-tool.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/interactive-rebase-tool.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
