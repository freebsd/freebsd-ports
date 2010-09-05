# New ports collection makefile for:	p5-libxml-enno
# Date created:		2010-03-03
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	libxml-enno
PORTVERSION=	1.02
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/E/EN/ENNO
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A group of perl modules for XML parsing

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml \
		${SITE_PERL}/Parse/Yapp/Parse.pm:${PORTSDIR}/devel/p5-Parse-Yapp
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml \
		${SITE_PERL}/Parse/Yapp/Parse.pm:${PORTSDIR}/devel/p5-Parse-Yapp

CONFLICTS=	p5-XML-DOM-[0-9]* p5-XML-Filter-DetectWS-[0-9]* \
		p5-XML-Filter-Reindent-[0-9]* p5-XML-Filter-SAXT-[0-9]* \
		p5-XML-RegExp-[0-9]* p5-XML-XQL-[0-9]*

PERL_CONFIGURE=	yes

MAN3=	XML::Checker.3 XML::Checker::Parser.3 XML::DOM.3 XML::DOM::AttDef.3 \
	XML::DOM::AttlistDecl.3 XML::DOM::Attr.3 XML::DOM::CDATASection.3 \
	XML::DOM::CharacterData.3 XML::DOM::Comment.3 \
	XML::DOM::DOMImplementation.3 XML::DOM::Document.3 \
	XML::DOM::DocumentFragment.3 XML::DOM::DocumentType.3 \
	XML::DOM::Element.3 XML::DOM::ElementDecl.3 XML::DOM::Entity.3 \
	XML::DOM::EntityReference.3 XML::DOM::NamedNodeMap.3 XML::DOM::Node.3 \
	XML::DOM::NodeList.3 XML::DOM::Notation.3 XML::DOM::Parser.3 \
	XML::DOM::PerlSAX.3 XML::DOM::ProcessingInstruction.3 \
	XML::DOM::Text.3 XML::DOM::ValParser.3 XML::DOM::XMLDecl.3 \
	XML::Filter::DetectWS.3 XML::Filter::Reindent.3 XML::Filter::SAXT.3 \
	XML::Handler::BuildDOM.3 XML::Handler::Composer.3 \
	XML::Handler::PrintEvents.3 XML::RegExp.3 XML::UM.3 XML::XQL.3 \
	XML::XQL::DOM.3 XML::XQL::Date.3 XML::XQL::Query.3 XML::XQL::Tutorial.3

.include <bsd.port.mk>
