# New ports collection makefile for:	jwasm
# Date created:        7 April 2009
# Whom:                Pedro F. Giffuni <giffunip@tutopia.com>
#
# $FreeBSD$
#

PORTNAME=	jwasm
PORTVERSION=	204
CATEGORIES=	devel
MASTER_SITES=	http://www.japheth.de/Download/JWasm/
DISTNAME=	JWasm${PORTVERSION}cs

MAINTAINER=	giffunip@tutopia.com
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
	@${GZIP_CMD} ${DOCSDIR}/*.txt
.endif

.include <bsd.port.mk>
