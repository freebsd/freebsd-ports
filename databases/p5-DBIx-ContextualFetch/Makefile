# New ports collection makefile for:	DBIx-ContextualFetch
# Date created:	   17 March 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	DBIx-ContextualFetch
PORTVERSION=	1.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Add contextual fetches to DBI

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBIx::ContextualFetch.3

.include <bsd.port.mk>
