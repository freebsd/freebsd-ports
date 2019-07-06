# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBD-mysql
PORTVERSION=	4.050
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CAPTTOFU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT?=	MySQL driver for the Perl5 Database Interface (DBI)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Devel-CheckLib>=1.09:devel/p5-Devel-CheckLib
RUN_DEPENDS=	p5-DBI>=1.08:databases/p5-DBI
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

CONFLICTS_INSTALL?=	p5-DBD-mysql[45][0-9]-[0-9]*

USES=		mysql perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	SSL
SSL_RUN_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay
SSL_CONFIGURE_OFF=	--nossl
SSL_CONFIGURE_ON=	--ssl
SSL_USES=		ssl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/mysql/mysql.so

.include <bsd.port.mk>
