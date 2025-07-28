PORTNAME=	bwa
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.19
CATEGORIES=	biology

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Burrows-Wheeler sequence aligner
WWW=		https://bio-bwa.sourceforge.net/ \
		https://sourceforge.net/projects/bio-bwa/ \
		https://github.com/lh3/bwa/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# Recheck these after 0.7.18 update
BROKEN_mips=	fails to compile: cc1: unrecognized command line option "-msse2"
BROKEN_mips64=	fails to compile: cc1: unrecognized command line option "-msse2"

BUILD_DEPENDS=	simde>0:devel/simde

USES=		gmake localbase perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	lh3
USE_PERL5=	run

SHEBANG_FILES=	qualfa2fq.pl xa2multi.pl

PLIST_FILES=	bin/bwa bin/qualfa2fq.pl bin/xa2multi.pl share/man/man1/bwa.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bwa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
