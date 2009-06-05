# New ports collection makefile for:	Finance::Quote
# Date created:		26 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Finance-Quote
PORTVERSION=	1.16
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Get stock and mutual fund quotes from various exchanges

BUILD_DEPENDS=	${SITE_PERL}/HTML/TableExtract.pm:${PORTSDIR}/www/p5-HTML-TableExtract \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::Quote.3 Finance::Quote::AEX.3 \
		Finance::Quote::AIAHK.3 Finance::Quote::ASEGR.3 \
		Finance::Quote::ASX.3 Finance::Quote::BMONesbittBurns.3 \
		Finance::Quote::Bourso.3 Finance::Quote::Cdnfundlibrary.3 \
		Finance::Quote::Currencies.3 \
		Finance::Quote::Cominvest.3 Finance::Quote::DWS.3 \
		Finance::Quote::Deka.3 Finance::Quote::FTPortfolios.3 \
		Finance::Quote::Fidelity.3 Finance::Quote::FinanceCanada.3 \
		Finance::Quote::Finanzpartner.3 Finance::Quote::Fool.3 \
		Finance::Quote::GoldMoney.3 \
		Finance::Quote::HEX.3 Finance::Quote::IndiaMutual.3 \
		Finance::Quote::LeRevenu.3 Finance::Quote::ManInvestments.3 \
		Finance::Quote::Morningstar.3 \
		Finance::Quote::NZX.3 Finance::Quote::Platinum.3 \
		Finance::Quote::SEB.3 Finance::Quote::TSP.3 \
		Finance::Quote::TSX.3 Finance::Quote::Tdefunds.3 \
		Finance::Quote::Tdwaterhouse.3 Finance::Quote::Tiaacref.3 \
		Finance::Quote::Troweprice.3 Finance::Quote::Trustnet.3 \
		Finance::Quote::USFedBonds.3 Finance::Quote::Union.3 \
		Finance::Quote::VWD.3 Finance::Quote::Yahoo::Asia.3 \
		Finance::Quote::Yahoo::Australia.3 \
		Finance::Quote::Yahoo::Base.3 Finance::Quote::Yahoo::Brasil.3 \
		Finance::Quote::Yahoo::Europe.3 Finance::Quote::Yahoo::NZ.3 \
		Finance::Quote::Yahoo::USA.3 Finance::Quote::ZA.3

.include <bsd.port.mk>
