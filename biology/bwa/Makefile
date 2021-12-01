PORTNAME=	bwa
PORTVERSION=	0.7.17
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	biology

PATCH_SITES=	https://github.com/lh3/bwa/commit/
PATCHFILES=	2a1ae7b6f34a96ea25be007ac9d91e57e9d32284.patch:-p1

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Burrows-Wheeler sequence aligner

LICENSE=	GPLv3

BROKEN_mips=		fails to compile: cc1: unrecognized command line option "-msse2"
BROKEN_mips64=		fails to compile: cc1: unrecognized command line option "-msse2"

BUILD_DEPENDS=	simde>0:devel/simde

USES=		gmake localbase perl5 shebangfix tar:bzip2
SHEBANG_FILES=	qualfa2fq.pl xa2multi.pl
USE_PERL5=	run

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

PLIST_FILES=	bin/bwa bin/qualfa2fq.pl bin/xa2multi.pl man/man1/bwa.1.gz

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
# Avoid #error in emmintrin.h
CFLAGS+=	-msse2
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bwa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
