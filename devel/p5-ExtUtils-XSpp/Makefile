# New ports collection makefile for:	p5-ExtUtils-XSpp
# Date created:				August 22nd 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-XSpp
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	XS for C++ in Perl

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/ParseXS.pm:${PORTSDIR}/devel/p5-ExtUtils-ParseXS \
		${SITE_PERL}/Test/Base.pm:${PORTSDIR}/devel/p5-Test-Base \
		${SITE_PERL}/Test/Differences.pm:${PORTSDIR}/devel/p5-Test-Differences

PERL_MODBUILD=	5.6.1+

MAN1=		xspp.1
MAN3=		ExtUtils::XSpp.3 \
		ExtUtils::XSpp::Cmd.3 \
		ExtUtils::XSpp::Exception.3 \
		ExtUtils::XSpp::Node.3 \
		ExtUtils::XSpp::Node::Access.3 \
		ExtUtils::XSpp::Node::Argument.3 \
		ExtUtils::XSpp::Node::Class.3 \
		ExtUtils::XSpp::Node::Comment.3 \
		ExtUtils::XSpp::Node::Constructor.3 \
		ExtUtils::XSpp::Node::Destructor.3 \
		ExtUtils::XSpp::Node::File.3 \
		ExtUtils::XSpp::Node::Function.3 \
		ExtUtils::XSpp::Node::Method.3 \
		ExtUtils::XSpp::Node::Module.3 \
		ExtUtils::XSpp::Node::Package.3 \
		ExtUtils::XSpp::Node::Raw.3 \
		ExtUtils::XSpp::Parser.3 \
		ExtUtils::XSpp::Typemap.3

.include <bsd.port.mk>
