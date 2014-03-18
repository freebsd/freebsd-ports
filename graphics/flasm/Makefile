# $FreeBSD$

PORTNAME=	flasm
PORTVERSION=	1.62
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.nowrap.de/download/
MASTER_SITE_SUBDIR=	kuriyama
DISTNAME=	flasm16src

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Command line assembler/disassembler of flash actionscript bytecode

USES=		bison dos2unix gmake zip
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/flasm

MAKE_ARGS=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flasm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
