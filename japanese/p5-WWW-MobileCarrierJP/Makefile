# New ports collection makefile for:	p5-WWW-MobileCarrierJP
# Date created:		2009-04-13
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	WWW-MobileCarrierJP
PORTVERSION=	0.44
CATEGORIES=	japanese www perl5
MASTER_SITES=	CPAN

MAINTAINER=	markun@onohara.to
COMMENT=	Scrape Japanese mobile carrier information

BUILD_DEPENDS=	p5-Moose>=0.60:${PORTSDIR}/devel/p5-Moose \
		p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-HTML-Selector-XPath>=0.03:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-TableExtract>=0:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-Web-Scraper>=0.24:${PORTSDIR}/www/p5-Web-Scraper \
		p5-libwww>=5.834:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-CAM-PDF>=0:${PORTSDIR}/textproc/p5-CAM-PDF

PERL_CONFIGURE=	yes

MAN3=		WWW::MobileCarrierJP::EZWeb::PictogramInfo.3 \
		WWW::MobileCarrierJP::ThirdForce::HTTPHeader.3 \
		WWW::MobileCarrierJP::EZWeb::DeviceID.3 \
		WWW::MobileCarrierJP::DoCoMo::Display.3 \
		WWW::MobileCarrierJP::AirHPhone::CIDR.3 \
		WWW::MobileCarrierJP::ThirdForce::CIDR.3 \
		WWW::MobileCarrierJP::ThirdForce::Service.3 \
		WWW::MobileCarrierJP::EZWeb::CIDR.3 \
		WWW::MobileCarrierJP::DoCoMo::Flash.3 \
		WWW::MobileCarrierJP::DoCoMo::PictogramInfo.3 \
		WWW::MobileCarrierJP::DoCoMo::UserAgent.3 \
		WWW::MobileCarrierJP::EZWeb::Model.3 \
		WWW::MobileCarrierJP::ThirdForce::PictogramInfo.3 \
		WWW::MobileCarrierJP::ThirdForce::UserAgent.3 \
		WWW::MobileCarrierJP::ThirdForce::Java.3 \
		WWW::MobileCarrierJP::DoCoMo::CIDR.3 \
		WWW::MobileCarrierJP::EZWeb::BREW.3 \
		WWW::MobileCarrierJP::DoCoMo::HTMLVersion.3 \
		WWW::MobileCarrierJP::DoCoMo::Java.3 \
		WWW::MobileCarrierJP.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
