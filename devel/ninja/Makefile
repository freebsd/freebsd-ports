PORTNAME=	ninja
PORTVERSION=	1.13.1
DISTVERSIONPREFIX=	v
PORTEPOCH=	4
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Small build system closest in spirit to Make
WWW=		https://ninja-build.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	ninja-build

PORTSCOUT=	limit:^1\.

PLIST_FILES=	bin/ninja
PORTDOCS=	README.md manual.asciidoc

OPTIONS_DEFINE=		DOCS BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/ninja
ZSH_PLIST_FILES=	share/zsh/site-functions/_ninja

# Set up the environment variables that ninja's configure.py recognizes and
# respect building with ccache.
NINJA_ENV=	AR="${AR}" \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}"
.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
NINJA_ENV+=	CXX="${CCACHE_BIN} ${CXX}"
.else
NINJA_ENV+=	CXX="${CXX}"
.endif

post-patch:
	@${REINPLACE_CMD} "s/'-g', //" ${WRKSRC}/configure.py

do-build:
	@(cd ${WRKSRC} && \
		${SETENVI} ${CONFIGURE_ENV} ${NINJA_ENV} ${PYTHON_CMD} configure.py --bootstrap --verbose)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
	    ${INSTALL_DATA} README.md doc/manual.asciidoc \
	    ${STAGEDIR}${DOCSDIR})

do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKSRC}/misc/bash-completion \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/ninja

do-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh-completion \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_ninja

do-test: build
	cd ${WRKSRC} && ./ninja ninja_test && ./ninja_test

.include <bsd.port.mk>
