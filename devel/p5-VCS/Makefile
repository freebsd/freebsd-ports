# New ports collection makefile for:   p5-VCS
# Date created:                27 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	VCS
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	VCS
PKGNAMEPREFIX=	p5-

MAINTAINER=	fuyuki@hadaly.org

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		diff-hist.1
MAN3=		VCS.3 VCS::Cvs.3 VCS::Dir.3 VCS::File.3 \
		VCS::Hms.3 VCS::Rcs.3 VCS::Version.3 VCS_dev.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
