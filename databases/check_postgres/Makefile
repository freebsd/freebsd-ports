# New ports collection makefile for:	nagios-check_postgres
# Date created:		2011-10-31
# Whom:			Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
#
# $FreeBSD$
#

PORTNAME=	check_postgres
PORTVERSION=	2.18.0
#PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	http://bucardo.org/downloads/

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Script for checking postgresql

RUN_DEPENDS=	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg

USE_PERL5=	Yes
PERL_CONFIGURE=	Yes

post-patch:
	mv ${WRKSRC}/check_postgres.pl ${WRKSRC}/check_postgres

.include <bsd.port.mk>
