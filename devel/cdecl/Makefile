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

USE_GCC=	any
ALL_TARGET=	${PORTNAME}
MAN1=		cdecl.1
MLINKS=		cdecl.1 c++decl.1
PORTDOCS=	testset testset++
PLIST_FILES=	bin/cdecl bin/c++decl


CONFLICTS=	cutils-[0-9]*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${DOCSDIR}
.endif

.include <bsd.port.mk>
