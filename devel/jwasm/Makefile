# New ports collection makefile for:	jwasm
# Date created:        7 April 2009
# Whom:                Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	jwasm
PORTVERSION=	207a
CATEGORIES=	devel
MASTER_SITES=	http://www.japheth.de/Download/JWasm/
DISTNAME=	JWasm${PORTVERSION}s

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of OpenWatcom's x86 assembler with AMD64 support

ONLY_FOR_ARCHS=	amd64 i386

USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	GccUnix.mak
NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	-qa

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/GccUnixR/jwasm ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/manual
	@${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${DOCSDIR}/manual
	@${GZIP_CMD} ${DOCSDIR}/*.txt ${DOCSDIR}/manual/*.txt
.endif

.include <bsd.port.mk>
