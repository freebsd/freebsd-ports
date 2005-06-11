# New ports collection makefile for:    p5-App-Info
# Date created:				19 May 2003
# Whom:	      				Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-Info
PORTVERSION=	0.25
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	App
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Interface for providing metadata about installed software packages

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	YES

MAN3=		App::Info::HTTPD.3 App::Info::Lib::Iconv.3 \
		App::Info::HTTPD::Apache.3 App::Info::Lib.3 App::Info::RDBMS.3 \
		App::Info::Lib::Expat.3 App::Info::Request.3 \
		App::Info::Handler::Print.3 App::Info::RDBMS::PostgreSQL.3 \
		App::Info::Util.3 App::Info::Handler.3 App::Info.3 \
		App::Info::Handler::Prompt.3 App::Info::Handler::Carp.3

.include <bsd.port.mk>
