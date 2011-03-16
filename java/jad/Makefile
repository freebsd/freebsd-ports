# New ports collection makefile for:	jad
# Date created:				27 September 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	jad
PORTVERSION=	1.5.8c
CATEGORIES=	java devel
MASTER_SITES=	http://www.varaneckas.com/sites/default/files/jad/
DISTNAME=	jad158c.freebsd

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java Decompiler

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/jad

PORTDOCS=	*

ONLY_FOR_ARCHS=	i386 amd64

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/jad ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
