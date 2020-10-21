# $FreeBSD$

PORTNAME=	duktape
DISTVERSION=	2.6.0
CATEGORIES=	lang devel
MASTER_SITES=	https://duktape.org/

MAINTAINER=	alfix86@gmail.com
COMMENT=	Embeddable Javascript engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tar:xz

MAKEFILE=	Makefile.cmdline
ALL_TARGET=	duk

PLIST_FILES=	bin/duk

PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/duk ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
