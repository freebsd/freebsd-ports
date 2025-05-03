PORTNAME=	Data-Swap
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	parv@pair.com
COMMENT=	XS module to swap the contents and types of referenced variables
WWW=		https://metacpan.org/release/Data-Swap

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 503700
BROKEN=         uses hidden Perl functions that are hidden after 5.37.0
.endif

.include <bsd.port.post.mk>
