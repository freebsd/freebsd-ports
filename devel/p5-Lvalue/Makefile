PORTNAME=	Lvalue
PORTVERSION=	0.21
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Add lvalue getters and setters to existing objects

USES=		perl5
USE_PERL5=	configure

post-patch::
	@${REINPLACE_CMD} -i '' -e 's|qw(can isa DOES VERSION)|(qw(can isa DOES VERSION))|g' \
		${WRKSRC}/lib/Lvalue.pm

.include <bsd.port.mk>
