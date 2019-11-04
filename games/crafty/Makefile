# Created by: Stefan Eggers <seggers@semyam.dinoco.de>
# $FreeBSD$

PORTNAME=	crafty
PORTVERSION=	25.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.craftychess.com/downloads/source/:src \
		http://www.craftychess.com/downloads/book/:data
DISTFILES=	crafty-${PORTVERSION}.zip:src \
		book.bin:data \
		start.pgn.gz:data
DIST_SUBDIR=	crafty
EXTRACT_ONLY=	crafty-${PORTVERSION}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chess program for playing and analyzing games

BROKEN_aarch64=		fails to compile: invokes amd64 assembler
BROKEN_armv6=		fails to compile: invokes amd64 assembler
BROKEN_armv7=		fails to compile: invokes amd64 assembler
BROKEN_i386=		fails to compile: invokes amd64 assembler
BROKEN_mips=		fails to compile: unrecognized command line option "-mpopcnt"
BROKEN_mips64=		fails to compile: unrecognized command line option "-mpopcnt"

USES=		gmake zip

ALL_TARGET=	unix-gcc
NO_WRKSUBDIR=	yes

WITH_BOOKDIR?=	${PREFIX}/lib/crafty
WITH_LOGDIR?=	/tmp
WITH_RCDIR?=	~/
WITH_TBDIR?=	${PREFIX}/lib/crafty/TB
WITH_PERSDIR?=	${PREFIX}/lib/crafty/cpf

OPT=		-DHASHSTATS -DTRACE -DBOOKDIR=\\\"${WITH_BOOKDIR}\\\" \
		-DLOGDIR=\\\"${WITH_LOGDIR}\\\" \
		-DRCDIR=\\\"${WITH_RCDIR}\\\" \
		-DTBDIR=\\\"${WITH_TBDIR}\\\" \
		-DPERSDIR=\\\"${WITH_PERSDIR}\\\" -DSKILL

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
OPT+=		-DCPUS=4
.else
OPT+=		-DCPUS=1 # disables x86 assembler
.endif

MAKE_ENV+=	opt="${OPT}" target=${OPSYS} CXFLAGS="${CXXFLAGS}"

post-extract:
	cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} book.bin start.pgn.gz ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/start.pgn.gz

post-build:
	(cd ${WRKSRC}; ./crafty bookpath=. <${FILESDIR}/books-building)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${STAGEDIR}${PREFIX}/bin/crafty
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/crafty/cpf
	${INSTALL_DATA} ${WRKSRC}/book.bin ${WRKSRC}/books.bin ${WRKSRC}/crafty.hlp \
		${STAGEDIR}${PREFIX}/lib/crafty

.include <bsd.port.post.mk>
