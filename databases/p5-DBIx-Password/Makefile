# New ports collection makefile for:	p5-DBIx-Password
# Date created:				March 17th 2002
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Password
PORTVERSION=	1.9
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to create a global password file for DB passwords

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		DBIx::Password.3

.include <bsd.port.mk>
