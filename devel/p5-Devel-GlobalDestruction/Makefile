# New ports collection makefile for:	devel/p5-Devel-GlobalDestruction
# Date created:				3 Sep 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-GlobalDestruction
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Expose PL_dirty, the flag which marks global destruction

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Sub-Exporter-Progressive>=0.001.002:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::GlobalDestruction.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-ExtUtils-CBuilder>=0.2700:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
.endif

.if ${PERL_LEVEL} < 501400
PLIST_SUB+=	PP="@comment " XS=""
.else
PLIST_SUB+=	PP="" XS="@comment "
.endif

.include <bsd.port.post.mk>
