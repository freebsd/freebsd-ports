# New ports collection makefile for:	devel/p5-Data-Hierarchy
# Date created:				Mar 15 2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Hierarchy
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Handle data in a hierarchical structure

PERL_CONFIGURE=	yes

MAN3=		Data::Hierarchy.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500700
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
