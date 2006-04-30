# New ports collection makefile for:    Module::Build::Kwalitee
# Date created:         2006-04-27
# Whom:                 Yuan-Chung Hsiao & <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Build-Kwalitee
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/ST/STIG
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Module::Build subclass with prepackaged tests

BUILD_DEPENDS=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Module-Build>=0.26.09:${PORTSDIR}/devel/p5-Module-Build \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	p5-File-Find-Rule>=0:${PORTSDIR}/devel/p5-File-Find-Rule

PERL_MODBUILD=	yes

MAN3=	Module::Build::Kwalitee.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
