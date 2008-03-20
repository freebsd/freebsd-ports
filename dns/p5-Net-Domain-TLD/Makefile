# New ports collection makefile for:	dns/p5-Net-Domain-TLD
# Date created:				30 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Domain-TLD
PORTVERSION=	1.67
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Look up and validate TLDs

BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Domain::TLD.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Storable>=0:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
