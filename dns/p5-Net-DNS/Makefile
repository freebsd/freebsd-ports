# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DNS
PORTVERSION=	1.25
PORTEPOCH=	1
CATEGORIES=	dns net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 interface to the DNS resolver, and dynamic updates

LICENSE=	MIT

TEST_DEPENDS=	p5-Digest-BubbleBabble>=0:security/p5-Digest-BubbleBabble \
		p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	--no-IPv6-tests --no-online-tests
NO_ARCH=	yes

OPTIONS_DEFINE=	IDN IDN2 IPV6 SSHFP TSIG
OPTIONS_DEFAULT=TSIG
IDN_DESC=	International Domain Names support via Net::LibIDN
IDN2_DESC=	International Domain Names support via Net::LibIDN2
SSHFP_DESC=	SSH2 Fingerprint support
TSIG_DESC=	Transaction Signature Support

IDN_BUILD_DEPENDS=	p5-Net-LibIDN>=0.12:dns/p5-Net-LibIDN
IDN_RUN_DEPENDS=	p5-Net-LibIDN>=0.12:dns/p5-Net-LibIDN
IDN2_BUILD_DEPENDS=	p5-Net-LibIDN2>=1:dns/p5-Net-LibIDN2
IDN2_RUN_DEPENDS=	p5-Net-LibIDN2>=1:dns/p5-Net-LibIDN2
SSHFP_BUILD_DEPENDS=	p5-Digest-BubbleBabble>=0.01:security/p5-Digest-BubbleBabble
SSHFP_RUN_DEPENDS=	p5-Digest-BubbleBabble>=0.01:security/p5-Digest-BubbleBabble
TSIG_BUILD_DEPENDS=	p5-Digest-HMAC>=1.03:security/p5-Digest-HMAC
TSIG_RUN_DEPENDS=	p5-Digest-HMAC>=1.03:security/p5-Digest-HMAC

.include <bsd.port.mk>
