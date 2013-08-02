# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	SOAP-WSDL
PORTVERSION=	2.00.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for SOAP with WSDL support

RUN_DEPENDS=	p5-Class-Std-Fast>=0:${PORTSDIR}/devel/p5-Class-Std-Fast \
		p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-TimeDate>=1.16:${PORTSDIR}/devel/p5-TimeDate \
		p5-XML-Parser>=2.36:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww\
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
		p5-Term-ReadKey>=2.30:${PORTSDIR}/devel/p5-Term-ReadKey
BUILD_DEPENDS=	p5-Class-Std-Fast>=0:${PORTSDIR}/devel/p5-Class-Std-Fast \
		p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-TimeDate>=1.16:${PORTSDIR}/devel/p5-TimeDate \
		p5-XML-Parser>=2.36:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	modbuild

MAN1=		wsdl2perl.pl.1
MAN3=		SOAP::WSDL.3 \
		SOAP::WSDL::Client.3 \
		SOAP::WSDL::Client::Base.3 \
		SOAP::WSDL::Definitions.3 \
		SOAP::WSDL::Deserializer::Hash.3 \
		SOAP::WSDL::Deserializer::SOM.3 \
		SOAP::WSDL::Deserializer::XSD.3 \
		SOAP::WSDL::Expat::Base.3 \
		SOAP::WSDL::Expat::Message2Hash.3 \
		SOAP::WSDL::Expat::MessageParser.3 \
		SOAP::WSDL::Expat::MessageStreamParser.3 \
		SOAP::WSDL::Expat::WSDLParser.3 \
		SOAP::WSDL::Factory::Deserializer.3 \
		SOAP::WSDL::Factory::Generator.3 \
		SOAP::WSDL::Factory::Serializer.3 \
		SOAP::WSDL::Factory::Transport.3 \
		SOAP::WSDL::Generator::Iterator::WSDL11.3 \
		SOAP::WSDL::Generator::PrefixResolver.3 \
		SOAP::WSDL::Generator::Template.3 \
		SOAP::WSDL::Generator::Template::Plugin::XSD.3 \
		SOAP::WSDL::Generator::Template::XSD.3 \
		SOAP::WSDL::Generator::Template::XSD::complexType.tt.3 \
		SOAP::WSDL::Generator::Template::XSD::complexType::POD::attributeSet.tt.3 \
		SOAP::WSDL::Generator::Template::XSD::element.tt.3 \
		SOAP::WSDL::Generator::Visitor.3 \
		SOAP::WSDL::Generator::Visitor::Typemap.3 \
		SOAP::WSDL::Manual.3 \
		SOAP::WSDL::Manual::CodeFirst.3 \
		SOAP::WSDL::Manual::Cookbook.3 \
		SOAP::WSDL::Manual::Deserializer.3 \
		SOAP::WSDL::Manual::FAQ.3 \
		SOAP::WSDL::Manual::Glossary.3 \
		SOAP::WSDL::Manual::Parser.3 \
		SOAP::WSDL::Manual::Serializer.3 \
		SOAP::WSDL::Manual::WS_I.3 \
		SOAP::WSDL::Manual::XSD.3 \
		SOAP::WSDL::SOAP::Typelib::Fault11.3 \
		SOAP::WSDL::Serializer::XSD.3 \
		SOAP::WSDL::Server.3 \
		SOAP::WSDL::Server::CGI.3 \
		SOAP::WSDL::Server::Mod_Perl2.3 \
		SOAP::WSDL::Server::Simple.3 \
		SOAP::WSDL::Transport::HTTP.3 \
		SOAP::WSDL::Transport::Loopback.3 \
		SOAP::WSDL::Transport::Test.3 \
		SOAP::WSDL::XSD::Schema::Builtin.3 \
		SOAP::WSDL::XSD::Typelib::Builtin.3 \
		SOAP::WSDL::XSD::Typelib::Builtin::list.3 \
		SOAP::WSDL::XSD::Typelib::ComplexType.3 \
		SOAP::WSDL::XSD::Typelib::Element.3 \
		SOAP::WSDL::XSD::Typelib::SimpleType.3

.include <bsd.port.mk>
