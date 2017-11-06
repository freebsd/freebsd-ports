# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Finance-Bitcoin
PORTVERSION=	0.902
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl interface to a bitcoin instance

BUILD_DEPENDS=	p5-JSON-RPC>=0.96:devel/p5-JSON-RPC \
		p5-Class-Accessor>=0.34:devel/p5-Class-Accessor \
		p5-Module-Signature>=0.66:security/p5-Module-Signature \
		p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-Object-AUTHORITY>=0:devel/p5-Object-Authority
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	-@${RM} ${WRKSRC}/lib/Finance/Bitcoin/API.pm.orig

.include <bsd.port.mk>
