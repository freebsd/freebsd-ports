# New ports collection makefile for:	File-Tail
# Date created:			19 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	File-Tail
PORTVERSION=	0.97
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeremy@external.org

BUILD_DEPENDS=	${site_perl}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

site_perl=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

PERL_CONFIGURE=	YES

MAN3=		File::Tail.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
