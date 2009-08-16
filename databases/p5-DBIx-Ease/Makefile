# New ports collection makefile for:	p5-DBIx-Ease
# Date created:	   21 july 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DBIx-Ease
PORTVERSION=	0.07
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_LOCAL:S/$/:local/} ${MASTER_SITE_PERL_CPAN:S/$/:cpan/}
MASTER_SITE_SUBDIR=	mat/:local DBIx/:cpan
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:local,cpan

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Less-code DBI interactions for all drivers

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN3=		DBIx::Ease.3

.include <bsd.port.mk>
