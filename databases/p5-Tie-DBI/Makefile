# New ports collection makefile for:	Tie-DBI
# Date created:				Thu Mar  8 06:56:59 2001
# Whom:					clive
#
# $FreeBSD$
#

PORTNAME=	Tie-DBI
PORTVERSION=	1.05
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module implementing Tie hash to a DBI handle

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

PERL_CONFIGURE=	yes

MAN3=		Tie::RDBM.3 Tie::DBI.3

.include <bsd.port.mk>
