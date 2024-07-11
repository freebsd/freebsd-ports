PORTNAME=	DBD-mysql
PORTVERSION=	5.005
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DVEEDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sirdice@gmail.com
COMMENT=	MySQL driver for the Perl5 Database Interface (DBI)
WWW=		https://metacpan.org/release/DBD-mysql

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Devel-CheckLib>=1.09:devel/p5-Devel-CheckLib
RUN_DEPENDS=	p5-DBI>=1.08:databases/p5-DBI
LIB_DEPENDS=	libunwind.so:devel/libunwind
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		compiler:c11 mysql perl5 ssl
USE_PERL5=	configure

CONFIGURE_ARGS=		${_CONFIGURE_ARGS_${CHOSEN_COMPILER_TYPE}}
_CONFIGURE_ARGS_gcc=	--libs="-L${PREFIX}/lib/gcc${GCC_DEFAULT} `mysql_config --libs | ${SED} 's/-pthread //'`"

CONFLICTS_INSTALL=	p5-DBD-mysql4

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/mysql/mysql.so

.include <bsd.port.pre.mk>

.if ${MYSQL_FLAVOUR} != mysql
IGNORE=use databases/p5-DBD-mysql4 or databases/p5-DBD-MariaDB instead
.endif

.include <bsd.port.post.mk>
