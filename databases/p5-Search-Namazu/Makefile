# New ports collection makefile for:	Search::Namazu
# Date created:		18 Jun 2002
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	Search-Namazu
PORTVERSION=	0.92
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.namazu.org/~knok/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		nmz.6:${PORTSDIR}/databases/namazu2

PERL_CONFIGURE=	YES
CONFIGURE_ENV=	PREFIX=${PREFIX}
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Search::Namazu.3

.include <bsd.port.mk>
