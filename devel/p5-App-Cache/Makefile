# New ports collection makefile for:	p5-App-Cache
# Date created:			09 May 2006
# Whom:				Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-Cache
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	App
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Easy application-level caching

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor/Chained/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir \
		${SITE_PERL}/HTTP/Cookies.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		App::Cache.3

.include <bsd.port.mk>
