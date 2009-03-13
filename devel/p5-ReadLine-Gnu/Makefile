# New ports collection makefile for:	p5-ReadLine-Gnu
# Date created:				19 February 1998
# Whom:	      				Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	ReadLine-Gnu
PORTVERSION=	1.17a
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Term-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl 5 module that allows Term::ReadLine to use GNU readline

PERL_CONFIGURE=	5.8.0+
WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

MAN3=		Term::ReadLine::Gnu.3

.include <bsd.port.mk>
