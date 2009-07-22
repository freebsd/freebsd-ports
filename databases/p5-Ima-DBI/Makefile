# New ports collection makefile for:	Ima-DBI
# Date created:		17 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Ima-DBI
PORTVERSION=	0.35
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/P/PE/PERRIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Database connection caching and organization

BUILD_DEPENDS=	${SITE_PERL}/DBIx/ContextualFetch.pm:${PORTSDIR}/databases/p5-DBIx-ContextualFetch \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Ima::DBI.3

.include <bsd.port.mk>
