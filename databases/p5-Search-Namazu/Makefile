# New ports collection makefile for:	Search::Namazu
# Date created:		18 Jun 2002
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	Search-Namazu
PORTVERSION=	0.96
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Search
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Namazu library module for perl

LIB_DEPENDS=	nmz.7:${PORTSDIR}/databases/namazu2

PERL_CONFIGURE=	YES

MAN3=		Search::Namazu.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Namazu.xs
.endif

.include <bsd.port.post.mk>
