# New ports collection makefile for:	p5-Tee
# Date created:		2011-02-04
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tee
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel perl5 textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Pure Perl emulation of GNU tee

BUILD_DEPENDS=	p5-IO-CaptureOutput>0:${PORTSDIR}/devel/p5-IO-CaptureOutput \
		p5-Probe-Perl>=0:${PORTSDIR}/sysutils/p5-Probe-Perl
RUN_DEPENDS=	p5-IO-CaptureOutput>0:${PORTSDIR}/devel/p5-IO-CaptureOutput

PERL_CONFIGURE=	yes

MAN1=	ptee.1
MAN3=	Tee::App.3 Tee.3

.include <bsd.port.mk>
