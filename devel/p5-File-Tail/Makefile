# New ports collection makefile for:	File-Tail
# Date created:			19 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	File-Tail
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeremy@external.org
COMMENT=	Perl Module to read the end of a file as it's appended to

BUILD_DEPENDS=	${site_perl}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

site_perl=	${SITE_PERL}/${PERL_ARCH}

PERL_CONFIGURE=	YES

MAN3=		File::Tail.3

.include <bsd.port.mk>
