# New ports collection makefile for:	dns/p5-Net-Domain-TLD
# Date created:				30 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Domain-TLD
PORTVERSION=	1.65
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Look up and validate TLDs

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Net::Domain::TLD.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^\s*our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e 's/.*warnings.*//' ${WRKSRC}/lib/Net/Domain/TLD.pm
.endif

.include <bsd.port.post.mk>
