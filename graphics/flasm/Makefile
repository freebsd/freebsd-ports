# $FreeBSD$

PORTNAME=	flasm
PORTVERSION=	1.62
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/kuriyama \
		http://www.nowrap.de/download/
DISTNAME=	flasm16src

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Command line assembler/disassembler of flash actionscript bytecode

USES=		bison dos2unix gmake gperf zip
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/flasm

MAKE_ARGS=	CFLAGS="${CFLAGS}"

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flasm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
