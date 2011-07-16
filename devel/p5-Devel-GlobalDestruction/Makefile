# New ports collection makefile for:	devel/p5-Devel-GlobalDestruction
# Date created:				3 Sep 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-GlobalDestruction
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Expose PL_dirty, the flag which marks global destruction

RUN_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_CONFIGURE=	yes

MAN3=		Devel::GlobalDestruction.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
PLIST_SUB+=	OLD_PERL_PLIST="" NEW_PERL_PLIST="@comment "
.else
PLIST_SUB+=	OLD_PERL_PLIST="@comment " NEW_PERL_PLIST=""
.endif

.include <bsd.port.post.mk>
