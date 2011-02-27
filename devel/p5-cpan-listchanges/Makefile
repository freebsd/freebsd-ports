# New ports collection makefile for:	cpan::listchanges
# Date created:		27 Feb 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpan-listchanges
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to list changes for CPAN modules

RUN_DEPENDS=	\
	p5-Algorithm-Diff>0:${PORTSDIR}/devel/p5-Algorithm-Diff \
	p5-CPAN-DistnameInfo>0:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Module-Metadata>0:${PORTSDIR}/devel/p5-Module-Metadata \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	cpan-listchanges.1
MAN3=	App::cpanlistchanges.3

.include <bsd.port.mk>
