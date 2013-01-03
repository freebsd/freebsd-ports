# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DNS
PORTVERSION=	0.72
CATEGORIES=	dns net perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the DNS resolver, and dynamic updates

# Warnings during build are harmless, the port does not need these to build
RUN_DEPENDS=	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC

TEST_DEPENDS=	p5-Test-Pod>0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Digest-BubbleBabble>0:${PORTSDIR}/security/p5-Digest-BubbleBabble

MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	IPV6 IDN DOCS
OPTIONS_DEFAULT=	IPV6

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--no-online-tests --no-IPv6-tests

MAN3=		Net::DNS.3 Net::DNS::Header.3 Net::DNS::Packet.3 \
		Net::DNS::Parameters.3 Net::DNS::Question.3 \
		Net::DNS::RR.3 Net::DNS::RR::A.3 \
		Net::DNS::RR::AFSDB.3 Net::DNS::RR::CNAME.3 \
		Net::DNS::RR::ISDN.3 Net::DNS::RR::L32.3 \
		Net::DNS::RR::L64.3 Net::DNS::RR::LP.3 \
		Net::DNS::RR::MG.3 Net::DNS::RR::NID.3 \
		Net::DNS::RR::TLSA.3 Net::DNS::RR::HINFO.3 Net::DNS::RR::IPSECKEY.3 \
		Net::DNS::RR::MINFO.3 Net::DNS::RR::MR.3 Net::DNS::RR::MX.3 \
		Net::DNS::RR::NS.3 Net::DNS::RR::PTR.3 Net::DNS::RR::RP.3 \
		Net::DNS::RR::RT.3 Net::DNS::RR::SOA.3 Net::DNS::RR::SRV.3 \
		Net::DNS::RR::TXT.3 Net::DNS::RR::X25.3 Net::DNS::Resolver.3 \
		Net::DNS::RR::AAAA.3 Net::DNS::RR::EID.3 Net::DNS::RR::LOC.3 \
		Net::DNS::RR::MB.3 Net::DNS::RR::NAPTR.3 \
		Net::DNS::RR::NIMLOC.3 Net::DNS::RR::NSAP.3 \
		Net::DNS::RR::NULL.3 Net::DNS::RR::PX.3 Net::DNS::Update.3 \
		Net::DNS::Nameserver.3 Net::DNS::RR::CERT.3 \
		Net::DNS::FAQ.3 Net::DNS::RR::TKEY.3 \
		Net::DNS::RR::OPT.3 Net::DNS::RR::TSIG.3 Net::DNS::RR::DNAME.3 \
		Net::DNS::RR::SSHFP.3 Net::DNS::Resolver::Base.3 \
		Net::DNS::Resolver::cygwin.3 Net::DNS::Resolver::MSWin32.3 \
		Net::DNS::Resolver::os2.3 Net::DNS::Resolver::UNIX.3\
	       	Net::DNS::Resolver::Recurse.3 Net::DNS::RR::APL.3 \
		Net::DNS::RR::DHCID.3 Net::DNS::Domain.3 \
		Net::DNS::DomainName.3 Net::DNS::Text.3 Net::DNS::Mailbox.3 \
		Net::DNS::ZoneFile.3 Net::DNS::RR::KX.3 Net::DNS::RR::HIP.3 \
		Net::DNS::RR::SPF.3

PORTDOCS=	Changes README TODO

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-INET6>0:${PORTSDIR}/net/p5-IO-Socket-INET6
.endif

.if ${PORT_OPTIONS:MIDN}
RUN_DEPENDS+=	p5-Net-LibIDN>0:${PORTSDIR}/dns/p5-Net-LibIDN
.endif

DOCSDIR=	${PREFIX}/share/doc/p5-Net-DNS

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
