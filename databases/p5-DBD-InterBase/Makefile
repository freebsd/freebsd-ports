PORTNAME=	DBD-InterBase
PORTVERSION=	0.48
PORTREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	yuri@rivera.ru
COMMENT=	DBI driver for InterBase/Firebird/Yaffil RDBMS server

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

USES=		perl5 firebird
USE_PERL5=	patch configure

post-patch:
		@${PERL} -pi -e 's,%%IB_BASE%%,${LOCALBASE},g' \
			${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
