# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DNS
PORTVERSION=	0.72
CATEGORIES=	dns net perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the DNS resolver, and dynamic updates

BUILD_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Digest-BubbleBabble>=0:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod

OPTIONS_DEFINE=	IDN IPV6 DOCS

CONFIGURE_ARGS=	--no-IPv6-tests --no-online-tests
USES=		perl5
USE_PERL5=	configure
DOCSDIR=	${PREFIX}/share/doc/p5-Net-DNS

PORTDOCS=	Changes README TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDN}
BUILD_DEPENDS+=	p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN
RUN_DEPENDS+=	p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN
.endif

.if ${PORT_OPTIONS:MIPV6}
BUILD_DEPENDS+=	p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6
RUN_DEPENDS+=	p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
