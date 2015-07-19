# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DNS
PORTVERSION=	1.01
CATEGORIES=	dns net perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the DNS resolver, and dynamic updates

LICENSE=	MIT

BUILD_DEPENDS=	p5-Digest-HMAC>=1.03:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-MIME-Base32>=1.01:${PORTSDIR}/converters/p5-MIME-Base32
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Digest-BubbleBabble>=0:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod

OPTIONS_DEFINE=	GOST IDN IPV6 SSHFP
GOST_DESC=	GOST support
SSHFP_DESC=	SSH2 Fingerprint support

CONFIGURE_ARGS=	--no-IPv6-tests --no-online-tests
NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

GOST_BUILD_DEPENDS=	p5-Digest-GOST>=0.06:${PORTSDIR}/security/p5-Digest-GOST
GOST_RUN_DEPENDS=	p5-Digest-GOST>=0.06:${PORTSDIR}/security/p5-Digest-GOST
IDN_BUILD_DEPENDS=	p5-Net-LibIDN>=0.12:${PORTSDIR}/dns/p5-Net-LibIDN
IDN_RUN_DEPENDS=	p5-Net-LibIDN>=0.12:${PORTSDIR}/dns/p5-Net-LibIDN
IPV6_BUILD_DEPENDS=	p5-IO-Socket-INET6>=2.01:${PORTSDIR}/net/p5-IO-Socket-INET6
IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=2.01:${PORTSDIR}/net/p5-IO-Socket-INET6
SSHFP_BUILD_DEPENDS=	p5-Digest-BubbleBabble>=0.01:${PORTSDIR}/security/p5-Digest-BubbleBabble
SSHFP_RUN_DEPENDS=	p5-Digest-BubbleBabble>=0.01:${PORTSDIR}/security/p5-Digest-BubbleBabble

.include <bsd.port.mk>
