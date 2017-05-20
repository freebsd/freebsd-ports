# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	bwa
PORTVERSION=	0.7.9a
CATEGORIES=	biology
MASTER_SITES=	SF/bio-bwa/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Burrows-Wheeler sequence aligner

LICENSE=	GPLv3

BROKEN_aarch64=		fails to compile: error: invalid conversion between vector type and integer type
BROKEN_powerpc64=	fails to compile: ksw.c: error: emmintrin.h: No such file or directory

USES=		perl5 shebangfix tar:bzip2
SHEBANG_FILES=	qualfa2fq.pl xa2multi.pl
USE_PERL5=	run

PLIST_FILES=	bin/bwa bin/qualfa2fq.pl bin/xa2multi.pl man/man1/bwa.1.gz

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
# Avoid #error in emmintrin.h
CFLAGS+=	-msse2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bwa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
