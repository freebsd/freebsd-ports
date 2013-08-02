# New ports collection makefile for:	p5-Google-Checkout
# Date created:				20 July 2007
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Google-Checkout
PORTVERSION=	1.1.1
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl implementation of Google Checkout (GCO)

RUN_DEPENDS=	p5-libwww>=5.65:${PORTSDIR}/www/p5-libwww \
		p5-XML-Simple>=2.09:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Crypt-SSLeay>=0.45:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Date-Manip>=5.40:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Digest-HMAC>=1.01:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-XML-Writer>=0.6:${PORTSDIR}/textproc/p5-XML-Writer
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAN3=	Google::Checkout::Command::AddMerchantOrderNumber.3 \
		Google::Checkout::Command::AddTrackingData.3 \
		Google::Checkout::Command::ArchiveOrder.3 \
		Google::Checkout::Command::AuthorizeOrder.3 \
		Google::Checkout::Command::CancelOrder.3 \
		Google::Checkout::Command::ChargeOrder.3 \
		Google::Checkout::Command::DeliverOrder.3 \
		Google::Checkout::Command::GCOCommand.3 \
		Google::Checkout::Command::ProcessOrder.3 \
		Google::Checkout::Command::RefundOrder.3 \
		Google::Checkout::Command::SendBuyerMessage.3 \
		Google::Checkout::Command::UnarchiveOrder.3 \
		Google::Checkout::General::AddressFilters.3 \
		Google::Checkout::General::ConfigReader.3 \
		Google::Checkout::General::DigitalContent.3 \
		Google::Checkout::General::Error.3 \
		Google::Checkout::General::FlatRateShipping.3 \
		Google::Checkout::General::GCO.3 \
		Google::Checkout::General::GiftCertificate.3 \
		Google::Checkout::General::MerchantCalculatedShipping.3 \
		Google::Checkout::General::MerchantCalculationCallback.3 \
		Google::Checkout::General::MerchantCalculationResult.3 \
		Google::Checkout::General::MerchantCalculationResults.3 \
		Google::Checkout::General::MerchantCalculations.3 \
		Google::Checkout::General::MerchantCheckoutFlow.3 \
		Google::Checkout::General::MerchantItem.3 \
		Google::Checkout::General::ParameterizedUrl.3 \
		Google::Checkout::General::ParameterizedUrls.3 \
		Google::Checkout::General::Pickup.3 \
		Google::Checkout::General::Shipping.3 \
		Google::Checkout::General::ShippingRestrictions.3 \
		Google::Checkout::General::ShoppingCart.3 \
		Google::Checkout::General::TaxRule.3 \
		Google::Checkout::General::TaxTable.3 \
		Google::Checkout::General::TaxTableAreas.3 \
		Google::Checkout::General::Util.3 \
		Google::Checkout::Notification::ChargeAmount.3 \
		Google::Checkout::Notification::ChargebackAmount.3 \
		Google::Checkout::Notification::Factory.3 \
		Google::Checkout::Notification::GCONotification.3 \
		Google::Checkout::Notification::NewOrder.3 \
		Google::Checkout::Notification::OrderStateChange.3 \
		Google::Checkout::Notification::RefundAmount.3 \
		Google::Checkout::Notification::RiskInformation.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
