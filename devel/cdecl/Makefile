# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	cdecl
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Explains complicated C/C++ declarations in plain English

USE_CSTD=	c89

USES=		readline
ALL_TARGET=	${PORTNAME}
PORTDOCS=	testset testset++
PLIST_FILES=	bin/cdecl bin/c++decl man/man1/cdecl.1.gz man/man1/c++decl.1.gz
MAKE_ENV+=	STAGEDIR=$(STAGEDIR)

CONFLICTS=	cutils-[0-9]*

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
