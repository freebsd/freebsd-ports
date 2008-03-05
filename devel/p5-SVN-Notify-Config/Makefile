# New ports collection makefile for:	SVN-Notify-Config
# Date created:		2008-02-12
# Whom:			Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Config
PORTVERSION=	0.0908
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	Perl module for config-driven Subversion notification

RUN_DEPENDS=	p5-SVN-Notify>=2.70:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-YAML>=0.62:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		SVN::Notify::Config.3

.include <bsd.port.mk>
