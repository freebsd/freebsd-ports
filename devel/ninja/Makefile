# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ninja
PORTVERSION=	1.4.0
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Ninja is a small build system closest in spirit to Make

LICENSE=	AL2

USE_GITHUB=	yes
GH_ACCOUNT=	martine
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	63d5b10

CONFLICTS=	irc/ninja-[0-9]*
USE_PYTHON=	yes

PLIST_FILES=	bin/ninja
PORTDOCS=	COPYING HACKING.md README manual.asciidoc

.include <bsd.port.options.mk>

do-build:
	@(cd ${WRKSRC} && \
		CXX=${CXX} CFLAGS="${CXXFLAGS}" ./bootstrap.py --verbose)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ninja ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} && \
	    ${INSTALL_DATA} COPYING HACKING.md README doc/manual.asciidoc \
	    ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
