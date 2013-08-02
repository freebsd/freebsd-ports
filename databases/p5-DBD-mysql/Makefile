# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBD-mysql
PORTVERSION=	4.023
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/00$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT?=	MySQL driver for the Perl5 Database Interface (DBI)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.08:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS?=	p5-Mysql-modules-[0-9]* p5-DBD-mysql[45][0-9]-[0-9]*

USE_MYSQL=	yes

USES=		perl5
USE_PERL5=	configure

MAN3=	Bundle::DBD::mysql.3 DBD::mysql.3 DBD::mysql::INSTALL.3

OPTIONS_DEFINE=	SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--ssl
RUN_DEPENDS+=		p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay
.endif

.include <bsd.port.mk>
