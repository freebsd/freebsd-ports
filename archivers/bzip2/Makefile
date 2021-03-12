# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bzip2
PORTVERSION=	1.0.8
CATEGORIES=	archivers
MASTER_SITES=	https://sourceware.org/pub/bzip2/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Block-sorting file compressor

LICENSE=	BZIP2
LICENSE_NAME=	BZIP2 license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe
CPE_VENDOR=	bzip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${STAGEDIR}${PREFIX}/bin
	${LN} -sf bzip2 ${STAGEDIR}${PREFIX}/bin/bunzip2
	${LN} -sf bzip2 ${STAGEDIR}${PREFIX}/bin/bzcat
	${LN} -sf bzip2 ${STAGEDIR}${PREFIX}/bin/bz2cat
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bzgrep ${STAGEDIR}${PREFIX}/bin
	${LN} -sf bzgrep ${STAGEDIR}${PREFIX}/bin/bzegrep
	${LN} -sf bzgrep ${STAGEDIR}${PREFIX}/bin/bzfgrep
	${INSTALL_SCRIPT} ${WRKSRC}/bzmore ${STAGEDIR}${PREFIX}/bin
	${LN} -sf bzmore ${STAGEDIR}${PREFIX}/bin/bzless
	${INSTALL_DATA} ${WRKSRC}/bzlib.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libbz2.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libbz2.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libbz2.so.1 ${STAGEDIR}${PREFIX}/lib/libbz2.so
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bzgrep.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bzmore.1 ${STAGEDIR}${PREFIX}/man/man1
	${LN} -sf bzip2.1 ${STAGEDIR}${PREFIX}/man/man1/bunzip2.1
	${LN} -sf bzip2.1 ${STAGEDIR}${PREFIX}/man/man1/bzcat.1
	${LN} -sf bzip2.1 ${STAGEDIR}${PREFIX}/man/man1/bz2cat.1
	${LN} -sf bzip2.1 ${STAGEDIR}${PREFIX}/man/man1/bzip2recover.1
	${LN} -sf bzgrep.1 ${STAGEDIR}${PREFIX}/man/man1/bzegrep.1
	${LN} -sf bzgrep.1 ${STAGEDIR}${PREFIX}/man/man1/bzfgrep.1
	${LN} -sf bzmore.1 ${STAGEDIR}${PREFIX}/man/man1/bzless.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/bzip2
	${INSTALL_DATA} ${WRKSRC}/manual* ${STAGEDIR}${PREFIX}/share/doc/bzip2
	${INSTALL_DATA} ${WRKSRC}/bzip2.txt ${STAGEDIR}${PREFIX}/share/doc/bzip2
	${STAGEDIR}${PREFIX}/bin/bzip2 -f ${STAGEDIR}${PREFIX}/share/doc/bzip2/manual.ps

.include <bsd.port.mk>
