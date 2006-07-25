# New ports collection makefile for:	p5-Class-Inflate
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Inflate
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Inflate HASH Object from Values in Database

RUN_DEPENDS=	${SITE_PERL}/Devel/Messenger.pm:${PORTSDIR}/devel/p5-Devel-Messenger
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite

PERL_MODBUILD=	yes

MAN3=		Class::Inflate.3

.include <bsd.port.mk>
