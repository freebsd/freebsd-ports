# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Perlish
PORTVERSION=	1.06
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GRUBER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perlish interface to SQL databases

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Devel-Caller>=0:devel/p5-Devel-Caller \
		p5-Keyword-Pluggable>=1.04:devel/p5-Keyword-Pluggable

USES=		gmake perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
