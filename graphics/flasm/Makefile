# New ports collection makefile for:	flasm
# Date created:		22 January 2002
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flasm
PORTVERSION=	1.62
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.nowrap.de/download/
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	flasm16src

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Command line assembler/disassembler of flash actionscript bytecode

PLIST_FILES=	bin/flasm
USE_ZIP=	YES
USE_GMAKE=	YES
USE_DOS2UNIX=	YES
USE_BISON=	build
NO_WRKSUBDIR=	YES
MAKE_ARGS=	CFLAGS="${CFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/flasm ${PREFIX}/bin

.include <bsd.port.mk>
