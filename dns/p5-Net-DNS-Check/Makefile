# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	Net-DNS-Check
PORTVERSION=	0.45
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Module for easy domain name checking

RUN_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS

USES=		perl5
USE_PERL5=	configure

MAN3=	Net::DNS::Check::Test::ns_count.3 Net::DNS::Check::Test::soa_expire_compare.3 \
	Net::DNS::Check::NSQuery.3 Net::DNS::Check::Test::soa_master_compare.3 \
	Net::DNS::Check::Test::mx_present.3 Net::DNS::Check::Test::mx_compare.3 \
	Net::DNS::Check::Test::soa_retry_compare.3 Net::DNS::Check::Test::unknown.3 \
	Net::DNS::Check::Test::host_ip_vs_ip_orig.3 Net::DNS::Check::Test::ns_vs_delegated.3 \
	Net::DNS::Check::Test::soa_serial_compare.3 Net::DNS::Check::Test::soa_retry_range.3 \
	Net::DNS::Check::HostsList.3 Net::DNS::Check::Test::host_ip_private.3 \
	Net::DNS::Check::Test::soa_expire_range.3 Net::DNS::Check::Config.3 \
	Net::DNS::Check::Test::soa_master_in_ns.3 Net::DNS::Check::Test::host_syntax.3 \
	Net::DNS::Check::Test::soa_refresh_range.3 Net::DNS::Check::Test::host_not_cname.3 \
	Net::DNS::Check::Test::ns_compare.3 Net::DNS::Check::Host.3 \
	Net::DNS::Check::Test.3 Net::DNS::Check::Test::soa_refresh_compare.3 \
	Net::DNS::Check::Test::soa_serial_syntax.3 Net::DNS::Check.3

.include <bsd.port.mk>
