PORTNAME=	Unicode-Japanese
PORTVERSION=	0.50
CATEGORIES=	japanese converters perl5
MASTER_SITES=	CPAN

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to handle Japanese character encodings
WWW=		https://metacpan.org/release/Unicode-Japanese

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:NCCFLAGS=*}
