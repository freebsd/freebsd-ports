# New ports collection makefile for:	flasm
# Date created:		22 January 2002
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flasm
PORTVERSION=	1.52
CATEGORIES=	graphics
#MASTER_SITES=	http://www.nowrap.de/download/
MASTER_SITES=	http://dist.bsdlab.org/
DISTNAME=	flasm152src

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Command line assembler/disassembler of flash actionscript bytecode

PLIST_FILES=	bin/flasm
USE_ZIP=	YES
USE_GMAKE=	YES
USE_BISON=	YES
NO_WRKSUBDIR=	YES
MAKE_ARGS=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flasm ${PREFIX}/bin

.include <bsd.port.mk>
