# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DNS
PORTVERSION=	1.06
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	dns net perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the DNS resolver, and dynamic updates

LICENSE=	MIT

TEST_DEPENDS=	p5-Digest-BubbleBabble>=0:security/p5-Digest-BubbleBabble \
		p5-Test-Pod>=0:devel/p5-Test-Pod

OPTIONS_DEFINE=	GOST IDN IPV6 SSHFP TSIG
OPTIONS_DEFAULT=TSIG
GOST_DESC=	GOST support
SSHFP_DESC=	SSH2 Fingerprint support
TSIG_DESC=	Transaction Signature Support

CONFIGURE_ARGS=	--no-IPv6-tests --no-online-tests
NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

GOST_BUILD_DEPENDS=	p5-Digest-GOST>=0.06:security/p5-Digest-GOST
GOST_RUN_DEPENDS=	p5-Digest-GOST>=0.06:security/p5-Digest-GOST
IDN_BUILD_DEPENDS=	p5-Net-LibIDN>=0.12:dns/p5-Net-LibIDN
IDN_RUN_DEPENDS=	p5-Net-LibIDN>=0.12:dns/p5-Net-LibIDN
SSHFP_BUILD_DEPENDS=	p5-Digest-BubbleBabble>=0.01:security/p5-Digest-BubbleBabble
SSHFP_RUN_DEPENDS=	p5-Digest-BubbleBabble>=0.01:security/p5-Digest-BubbleBabble
TSIG_BUILD_DEPENDS=	p5-Digest-HMAC>=1.03:security/p5-Digest-HMAC
TSIG_RUN_DEPENDS=	p5-Digest-HMAC>=1.03:security/p5-Digest-HMAC

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPV6} && ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-IO-Socket-IP>=0.32:net/p5-IO-Socket-IP
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.32:net/p5-IO-Socket-IP
.endif

.include <bsd.port.post.mk>
