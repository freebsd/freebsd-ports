# $FreeBSD$

PORTNAME=	X-Tiny
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Base class for a bare-bones exception factory

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_PERL_REL}/X/Tiny.pm \
		${SITE_PERL_REL}/X/Tiny/Base.pm \
		${SITE_MAN3_REL}/X::Tiny.3.gz \
		${SITE_MAN3_REL}/X::Tiny::Base.3.gz

pre-install:
		${RM} ${WRKSRC}/blib/lib/X/README.pod
 
.include <bsd.port.mk>
