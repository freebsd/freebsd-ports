PORTNAME=	DBD-InterBase
PORTVERSION=	0.48
PORTREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	yuri@rivera.ru
COMMENT=	DBI driver for InterBase/Firebird/Yaffil RDBMS server
WWW=		https://metacpan.org/release/DBD-InterBase

LICENSE=	NONE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

USES=		perl5 firebird
USE_PERL5=	patch configure

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
		@${PERL} -pi -e 's,%%IB_BASE%%,${LOCALBASE},g' \
			${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
