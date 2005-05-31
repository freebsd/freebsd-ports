# New ports collection makefile for:	Search::Namazu
# Date created:		18 Jun 2002
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	Search-Namazu
PORTVERSION=	0.92
PORTREVISION=	5
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.namazu.org/~knok/
PKGNAMEPREFIX=	p5-

DEPRECATED=	"not available on namazu.org, author's site, or CPAN"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Namazu library module for perl

LIB_DEPENDS=	nmz.7:${PORTSDIR}/databases/namazu2

PERL_CONFIGURE=	YES
USE_GETTEXT=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX}
MAN3=		Search::Namazu.3

.include <bsd.port.mk>
