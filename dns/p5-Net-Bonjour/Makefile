# $FreeBSD$

PORTNAME=	Net-Bonjour
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHLIGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for DNS service discovery

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-DNS>=0.5:dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's/my $$ans = .*/my $$ans = "n";/g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
