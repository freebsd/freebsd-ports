# $FreeBSD$

PORTNAME=	Data-AMF
PORTVERSION=	0.09
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to serialize, deserialize AMF data

RUN_DEPENDS=	\
	p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
	p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Data::AMF.3 \
	Data::AMF::Formatter.3 \
	Data::AMF::Formatter::AMF0.3 \
	Data::AMF::Formatter::AMF3.3 \
	Data::AMF::Header.3 \
	Data::AMF::IO.3 \
	Data::AMF::Message.3 \
	Data::AMF::Packet.3 \
	Data::AMF::Parser.3 \
	Data::AMF::Parser::AMF0.3 \
	Data::AMF::Parser::AMF3.3 \
	Data::AMF::Remoting.3 \
	Data::AMF::Type::Boolean.3 \
	Data::AMF::Type::ByteArray.3 \
	Data::AMF::Type::Null.3

NO_STAGE=	yes
.include <bsd.port.mk>
