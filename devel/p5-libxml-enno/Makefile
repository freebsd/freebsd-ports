# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	libxml-enno
PORTVERSION=	1.02
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ENNO
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A group of perl modules for XML parsing

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml \
		p5-Parse-Yapp>=0:${PORTSDIR}/devel/p5-Parse-Yapp
RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml \
		p5-Parse-Yapp>=0:${PORTSDIR}/devel/p5-Parse-Yapp

CONFLICTS=	p5-XML-DOM-[0-9]* p5-XML-Filter-DetectWS-[0-9]* \
		p5-XML-Filter-Reindent-[0-9]* p5-XML-Filter-SAXT-[0-9]* \
		p5-XML-RegExp-[0-9]* p5-XML-XQL-[0-9]*

USES=		perl5
USE_PERL5=	configure

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

NO_STAGE=	yes
.include <bsd.port.mk>
