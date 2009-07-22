# New ports collection makefile for:	p5-Cache-BDB
# Date created:		2006-07-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Cache-BDB
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	An object caching wrapper around BerkeleyDB

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB

PERL_CONFIGURE=	yes

MAN3=		Cache::BDB.3

.include <bsd.port.mk>
