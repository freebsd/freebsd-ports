# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	IOC
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight IOC (Inversion of Control) framework

BUILD_DEPENDS=	p5-Class-Throwable>=0:${PORTSDIR}/devel/p5-Class-Throwable \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Class-StrongSingleton>=0:${PORTSDIR}/devel/p5-Class-StrongSingleton \
		p5-Class-Interfaces>=0:${PORTSDIR}/devel/p5-Class-Interfaces
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		IOC.3 IOC::Config::XML.3 IOC::Config::XML::SAX::Handler.3 \
		IOC::Container.3 IOC::Container::MethodResolution.3 \
		IOC::Exceptions.3 IOC::Interfaces.3 IOC::Proxy.3 \
		IOC::Proxy::Interfaces.3 IOC::Registry.3 IOC::Service.3 \
		IOC::Service::ConstructorInjection.3 IOC::Service::Literal.3 \
		IOC::Service::Parameterized.3 IOC::Service::Prototype.3 \
		IOC::Service::Prototype::ConstructorInjection.3 \
		IOC::Service::Prototype::SetterInjection.3 \
		IOC::Service::SetterInjection.3 \
		IOC::Visitor::SearchForContainer.3 \
		IOC::Visitor::SearchForService.3 IOC::Visitor::ServiceLocator.3 \
		Test::IOC.3

.include <bsd.port.mk>
