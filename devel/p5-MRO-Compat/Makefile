# Created by: lbr
# $FreeBSD$

PORTNAME=	MRO-Compat
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Add mro::* interface compatibility for Perls < 5.9.5

BUILD_DEPENDS=	p5-Class-C3>=0.19:${PORTSDIR}/devel/p5-Class-C3
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MRO::Compat.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^if, .. m,}$$,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
