# New ports collection makefile for:	p5-File-MMagic
# Date created:		25 February 2000
# Whom:	      		Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	File-MMagic
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KN/KNOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org

USE_PERL5=	YES

MAN3=		File::MMagic.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
