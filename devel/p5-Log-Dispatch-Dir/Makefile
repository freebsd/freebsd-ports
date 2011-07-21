# New ports collection makefile for:	p5-Log-Dispatch-Dir
# Date created:		2011-07-21
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-Dir
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Log messages to separate files in a directory, with rotate options

RUN_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Probe-Perl>=0:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-Taint-Util>=0:${PORTSDIR}/devel/p5-Taint-Util

PERL_MODBUILD=	5.10.0+

MAN3=		Log::Dispatch::Dir.3

.include <bsd.port.mk>
