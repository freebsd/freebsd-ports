# New ports collection makefile for:	IOC
# Date created:	   22 Feb 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	IOC
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Lightweight IOC (Inversion of Control) framework

BUILD_DEPENDS=	${SITE_PERL}/Class/Throwable.pm:${PORTSDIR}/devel/p5-Class-Throwable \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Class/StrongSingleton.pm:${PORTSDIR}/devel/p5-Class-StrongSingleton \
		${SITE_PERL}/Class/Interfaces.pm:${PORTSDIR}/devel/p5-Class-Interfaces
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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
