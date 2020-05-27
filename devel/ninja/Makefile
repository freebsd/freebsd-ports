# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ninja
PORTVERSION=	1.10.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	2
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Small build system closest in spirit to Make

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	ninja-build

CONFLICTS=	irc/ninja-[0-9]*
USES=		python

PLIST_FILES=	bin/ninja
PORTDOCS=	README.md manual.asciidoc

OPTIONS_DEFINE=		DOCS BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/ninja
ZSH_PLIST_FILES=	share/zsh/site-functions/_ninja

post-patch:
	@${REINPLACE_CMD} "s/'-g', //" ${WRKSRC}/configure.py

do-build:
	@(cd ${WRKSRC} && \
		CXX="${CXX}" CFLAGS="${CXXFLAGS}" ${PYTHON_CMD} configure.py --bootstrap)

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
