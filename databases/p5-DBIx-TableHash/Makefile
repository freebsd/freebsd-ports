PORTNAME=	DBIx-TableHash
CATEGORIES=	databases perl5
PORTVERSION=	1.05
PORTREVISION=	2
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHTHORMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tie a hash to a MySQL table plus SQL utilities
WWW=		https://christhorman.com/projects/perl/DBIx-TableHash/

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${DBD_MYSQL}

USES=		mysql perl5
USE_PERL5=	configure

.include <bsd.port.mk>
