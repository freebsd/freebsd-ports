# New ports collection makefile for:	p5-perlbrew
# Date created:		2010-10-20
# Whom:			ports@c0decafe.net <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=		perlbrew
PORTVERSION=		0.10
CATEGORIES=		devel perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	../../authors/id/G/GU/GUGOD
PKGNAMEPREFIX=		p5-
DISTNAME=		App-${PORTNAME}-${PORTVERSION}

MAINTAINER=		ports@c0decafe.net
COMMENT=		Perl Environment manager

BUILD_DEPENDS=		p5-File-Path-Tiny>=0.1:${PORTSDIR}/devel/p5-File-Path-Tiny\
			p5-HTTP-Lite>=2.2:${PORTSDIR}/www/p5-HTTP-Lite
RUN_DEPENDS=		${BUILD_DEPENDS}

PERL_CONFIGURE=yes

MAN1=	perlbrew.1
MAN3=	App::perlbrew.3

.include <bsd.port.mk>
