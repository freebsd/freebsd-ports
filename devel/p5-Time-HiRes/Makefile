# New ports collection makefile for:	p5-Time-HiRes
# Date created:			13 June 1999
# Whom:				Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	Time-HiRes
PORTVERSION=	01.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes

MAN3=		Time::HiRes.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
