# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBD-mysql
PORTVERSION=	4.033
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT?=	MySQL driver for the Perl5 Database Interface (DBI)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.08:databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

CONFLICTS_INSTALL?=	p5-DBD-mysql[45][0-9]-[0-9]*

USE_MYSQL=	yes
USE_PERL5=	configure
USES=		perl5

OPTIONS_DEFINE=	SSL
SSL_BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay
SSL_RUN_DEPENDS=	${SSL_BUILD_DEPENDS}
SSL_CONFIGURE_ON=	--ssl

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/mysql/mysql.so

.include <bsd.port.mk>
