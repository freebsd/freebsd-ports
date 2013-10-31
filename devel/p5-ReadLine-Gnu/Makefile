# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	ReadLine-Gnu
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Term-${PORTNAME}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl 5 module that allows Term::ReadLine to use GNU readline

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

test:	build
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
