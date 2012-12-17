# $FreeBSD$

PORTNAME=	Exception-Class
PORTVERSION=	1.36
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Real exception classes in Perl

LICENSE=	ART20

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0.02:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Devel-StackTrace>=1.20:${PORTSDIR}/devel/p5-Devel-StackTrace
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Exception::Class.3 Exception::Class::Base.3

.include <bsd.port.mk>
