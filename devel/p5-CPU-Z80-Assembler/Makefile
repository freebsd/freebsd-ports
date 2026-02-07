PORTNAME=	CPU-Z80-Assembler
PORTVERSION=	2.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Z80 assembler written in Perl
WWW=		https://metacpan.org/dist/CPU-Z80-Assembler

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/ARTISTIC.txt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Asm-Preproc>=1.00:devel/p5-Asm-Preproc \
		p5-Capture-Tiny>=0.48:devel/p5-Capture-Tiny \
		p5-Path-Tiny>=0.122:devel/p5-Path-Tiny \
		p5-Regexp-Trie>=0.02:devel/p5-Regexp-Trie

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
