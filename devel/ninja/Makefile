# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ninja
PORTVERSION=	1.7.1
DISTVERSIONPREFIX=	v
PORTEPOCH=	2
CATEGORIES=	devel

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Ninja is a small build system closest in spirit to Make

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	martine

CONFLICTS=	irc/ninja-[0-9]*
USES=		python:build

PLIST_FILES=	bin/ninja
PORTDOCS=	HACKING.md README manual.asciidoc

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s/'-g', //" ${WRKSRC}/configure.py

do-build:
	@(cd ${WRKSRC} && \
		CXX="${CXX}" CFLAGS="${CXXFLAGS}" ${PYTHON_CMD} configure.py --bootstrap)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
	    ${INSTALL_DATA} HACKING.md README doc/manual.asciidoc \
	    ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
