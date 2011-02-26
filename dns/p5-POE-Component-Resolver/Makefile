# New ports collection makefile for:	devel/p5-POE-Component-Resolver
# Date created:				21 February 2011
# Whom:					Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Resolver
PORTVERSION=	0.911
CATEGORIES=	dns devel perl5
MASTER_SITES=	CPAN/${PORTNAME:C/-.*//}/RCAPUTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@beardz.net
COMMENT=	A non-blocking getaddrinfo() resolver

BUILD_DEPENDS=	p5-POE>=1.299:${PORTSDIR}/devel/p5-POE \
		p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Socket-GetAddrInfo>=0.19:${PORTSDIR}/net/p5-Socket-GetAddrInfo \
		p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Resolver.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Storable>=2.18:${PORTSDIR}/devel/p5-Storable \
		p5-Time-HiRes>=1.9711:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS+=	p5-Storable>=2.18:${PORTSDIR}/devel/p5-Storable \
		p5-Time-HiRes>=1.9711:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
