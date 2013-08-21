# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Finance-Quote
PORTVERSION=	1.18
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get stock and mutual fund quotes from various exchanges

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-HTML-TableExtract>=0:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		Finance::Quote.3 \
		Finance::Quote::AEX.3 \
		Finance::Quote::AIAHK.3 \
		Finance::Quote::ASEGR.3 \
		Finance::Quote::ASX.3 \
		Finance::Quote::BMONesbittBurns.3 \
		Finance::Quote::BSERO.3 \
		Finance::Quote::Bourso.3 \
		Finance::Quote::Cdnfundlibrary.3 \
		Finance::Quote::Cominvest.3 \
		Finance::Quote::Currencies.3 \
		Finance::Quote::DWS.3 \
		Finance::Quote::Deka.3 \
		Finance::Quote::FTPortfolios.3 \
		Finance::Quote::Fidelity.3 \
		Finance::Quote::FinanceCanada.3 \
		Finance::Quote::Finanzpartner.3 \
		Finance::Quote::Fool.3 \
		Finance::Quote::GoldMoney.3 \
		Finance::Quote::HEX.3 \
		Finance::Quote::HU.3 \
		Finance::Quote::IndiaMutual.3 \
		Finance::Quote::LeRevenu.3 \
		Finance::Quote::ManInvestments.3 \
		Finance::Quote::Morningstar.3 \
		Finance::Quote::NZX.3 \
		Finance::Quote::Platinum.3 \
		Finance::Quote::SEB.3 \
		Finance::Quote::TSP.3 \
		Finance::Quote::TSX.3 \
		Finance::Quote::Tdefunds.3 \
		Finance::Quote::Tdwaterhouse.3 \
		Finance::Quote::Tiaacref.3 \
		Finance::Quote::Troweprice.3 \
		Finance::Quote::Trustnet.3 \
		Finance::Quote::USFedBonds.3 \
		Finance::Quote::Union.3 \
		Finance::Quote::VWD.3 \
		Finance::Quote::Yahoo::Asia.3 \
		Finance::Quote::Yahoo::Australia.3 \
		Finance::Quote::Yahoo::Base.3 \
		Finance::Quote::Yahoo::Brasil.3 \
		Finance::Quote::Yahoo::Europe.3 \
		Finance::Quote::Yahoo::NZ.3 \
		Finance::Quote::Yahoo::USA.3 \
		Finance::Quote::ZA.3

post-patch:
	@${FIND} ${WRKSRC}/lib/Finance/ -name '*.orig' -delete

.include <bsd.port.mk>
