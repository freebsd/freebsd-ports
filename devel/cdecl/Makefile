# ex:ts=8
# Ports collection makefile for:  cdecl
# Date created:			  Sat Sep 04, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	cdecl
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Explains complicated C/C++ declarations in plain English

ALL_TARGET=	${PORTNAME}
MAN1=		cdecl.1
MLINKS=		cdecl.1 c++decl.1
PORTDOCS=	testset testset++
PLIST_FILES=	bin/cdecl bin/c++decl

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/testset* ${DOCSDIR}
.endif

.include <bsd.port.mk>
