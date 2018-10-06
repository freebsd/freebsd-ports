# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Perlish
PORTVERSION=	0.64
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GRUBER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perlish interface to SQL databases

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>0:databases/p5-DBI \
		p5-PadWalker>0:devel/p5-PadWalker

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
