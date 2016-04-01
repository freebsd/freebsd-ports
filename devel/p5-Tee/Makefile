# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tee
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	devel perl5 textproc
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Pure Perl emulation of GNU tee

BUILD_DEPENDS=	p5-IO-CaptureOutput>0:devel/p5-IO-CaptureOutput \
		p5-Probe-Perl>=0:sysutils/p5-Probe-Perl
RUN_DEPENDS=	p5-IO-CaptureOutput>0:devel/p5-IO-CaptureOutput

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
