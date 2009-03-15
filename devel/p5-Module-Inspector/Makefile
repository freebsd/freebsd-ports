# New ports collection makefile for:	p5-Module-Inspector
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Module-Inspector
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	An integrated API for inspecting Perl distributions

BUILD_DEPENDS=	${SITE_PERL}/File/Find/Rule/VCS.pm:${PORTSDIR}/devel/p5-File-Find-Rule-VCS \
		${SITE_PERL}/File/Find/Rule/Perl.pm:${PORTSDIR}/devel/p5-File-Find-Rule-Perl \
		${SITE_PERL}/Module/Extract.pm:${PORTSDIR}/devel/p5-Module-Extract \
		${SITE_PERL}/Module/Manifest.pm:${PORTSDIR}/devel/p5-Module-Manifest \
		${SITE_PERL}/Module/Math/Depends.pm:${PORTSDIR}/devel/p5-Module-Math-Depends \
		${SITE_PERL}/PPI.pm:${PORTSDIR}/textproc/p5-PPI \
		${SITE_PERL}/YAML/Tiny.pm:${PORTSDIR}/textproc/p5-YAML-Tiny \
		${SITE_PERL}/${PERL_ARCH}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Module::Inspector.3

.include <bsd.port.mk>
