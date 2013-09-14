# New ports collection makefile for:	p5-Finance-Bitcoin
# Date created:		2011-04-02
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Finance-Bitcoin
PORTVERSION=	0.004
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl interface to a bitcoin instance

BUILD_DEPENDS=	p5-JSON-RPC>=0.96:${PORTSDIR}/devel/p5-JSON-RPC \
		p5-Class-Accessor>=0.34:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Module-Signature>=0.66:${PORTSDIR}/security/p5-Module-Signature \
		p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Any-Moose>=0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Object-AUTHORITY>=0:${PORTSDIR}/devel/p5-Object-Authority
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Finance::Bitcoin::API.3 \
	Finance::Bitcoin::Address.3 \
	Finance::Bitcoin::Wallet.3 \
	Finance::Bitcoin.3

.include <bsd.port.pre.mk>

post-patch:
	-@${RM} ${WRKSRC}/lib/Finance/Bitcoin/API.pm.orig

.include <bsd.port.post.mk>
