PORTNAME=	mysql-genocide
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSOLIV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parallel operation on MySQL processlist
WWW=		https://metacpan.org/release/RSOLIV/mysql-genocide-0.03

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${DBD_MYSQL}

USES=		mysql perl5
USE_PERL5=	configure

.include <bsd.port.mk>
