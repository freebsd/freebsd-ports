# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	ReadLine-Gnu
PORTVERSION=	1.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Term-${PORTNAME}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl 5 module that allows Term::ReadLine to use GNU readline

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5 readline
CFLAGS+=	${CPPFLAGS}
USE_PERL5=	configure

.include <bsd.port.mk>
