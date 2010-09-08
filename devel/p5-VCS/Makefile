# New ports collection makefile for:   p5-VCS
# Date created:                27 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	VCS
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for generic Version Control System access in Perl

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		diff-hist.1
MAN3=		VCS.3 VCS::Cvs.3 VCS::Dir.3 VCS::File.3 \
		VCS::Rcs.3 VCS::Version.3 VCS_dev.3

.include <bsd.port.mk>
