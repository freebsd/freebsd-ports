# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	cdecl
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	SUNSITE/devel/lang/c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Explains complicated C/C++ declarations in plain English

CONFLICTS=	cutils-[0-9]*

USES=		readline
USE_CSTD=	c89
ALL_TARGET=	${PORTNAME}
MAKE_ENV+=	STAGEDIR=$(STAGEDIR)

PLIST_FILES=	bin/cdecl bin/c++decl man/man1/cdecl.1.gz man/man1/c++decl.1.gz
PORTDOCS=	testset testset++

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
