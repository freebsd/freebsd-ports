# New ports collection makefile for:	p5-Net-DNS
# Version required:			0.07
# Date created:				April 5th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1997/04/20 13:52:51 wosch Exp $
#

DISTNAME=	Net-DNS-0.07
PKGNAME=	p5-Net-DNS-0.07
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/IO/Socket.pm:${PORTSDIR}/net/p5-IO/
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		Net::DNS.3 Net::DNS::Header.3 Net::DNS::Packet.3 \
		Net::DNS::Question.3 Net::DNS::RR.3 Net::DNS::RR::A.3 \
		Net::DNS::RR::AFSDB.3 Net::DNS::RR::CNAME.3 Net::DNS::RR::HINFO.3 \
		Net::DNS::RR::ISDN.3 Net::DNS::RR::MG.3 Net::DNS::RR::MINFO.3 \
		Net::DNS::RR::MR.3 Net::DNS::RR::MX.3 Net::DNS::RR::NS.3 Net::DNS::RR::PTR.3 \
		Net::DNS::RR::RP.3 Net::DNS::RR::RT.3 Net::DNS::RR::SOA.3 Net::DNS::RR::SRV.3 \
		Net::DNS::RR::TXT.3 Net::DNS::RR::X25.3 Net::DNS::Resolver.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
