# Created by: Sergey Skvortsov <skv@FreeBSD.org>

PORTNAME=	DBD-mysql
PORTVERSION=	4.050
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CAPTTOFU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MySQL driver for the Perl5 Database Interface (DBI)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Devel-CheckLib>=1.09:devel/p5-Devel-CheckLib
RUN_DEPENDS=	p5-DBI>=1.08:databases/p5-DBI
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		compiler:c11 mysql perl5
USE_PERL5=	configure

CONFIGURE_ARGS=		${_CONFIGURE_ARGS_${CHOSEN_COMPILER_TYPE}}
_CONFIGURE_ARGS_gcc=	--libs="-L${PREFIX}/lib/gcc${GCC_DEFAULT} `mysql_config --libs | ${SED} 's/-pthread //'`"

CONFLICTS_INSTALL=	p5-DBD-mysql[45][0-9]-[0-9]*

OPTIONS_DEFINE=		SSL
OPTIONS_DEFAULT=	SSL

SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay
SSL_USES=		ssl
SSL_CONFIGURE_ON=	--ssl
SSL_CONFIGURE_OFF=	--nossl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/mysql/mysql.so

.include <bsd.port.mk>
