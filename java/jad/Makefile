# New ports collection makefile for:	jad
# Date created:				27 September 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	jad
PORTVERSION=	1.5.8c
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	jadfb158

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jad, a Java decompiler

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/jad

.if !defined(NOPORTDOCS)
PORTDOCS=	Readme.txt
.endif

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/jad ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/jad
	@${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/jad/
.endif

.include <bsd.port.post.mk>
