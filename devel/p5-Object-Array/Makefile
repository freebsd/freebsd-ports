# New ports collection makefile for:	p5-Object-Array
# Date created:		2006-08-30
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Object-Array
PORTVERSION=	0.060
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Array references with accessors

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/Sub/Exporter.pm:${PORTSDIR}/devel/p5-Sub-Exporter \
		${SITE_PERL}/Sub/Install.pm:${PORTSDIR}/devel/p5-Sub-Install \
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Object::Array.3 Object::Array::Plugin::Builtins.3 \
		Object::Array::Plugin::ListMoreUtils.3

.include <bsd.port.mk>
