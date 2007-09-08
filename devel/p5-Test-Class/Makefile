# New ports collection makefile for:    p5-Test-Class
# Date created:				January 27th 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Class
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Class - Easily create test classes in an xUnit style

RUN_DEPENDS=	p5-Devel-Symdump>=2.03:${PORTSDIR}/devel/p5-Devel-Symdump

PERL_MODBUILD=	yes

MAN3=		Test::Class.3 \
		Test::Class::Load.3 \
		Test::Class::MethodInfo.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500702
RUN_DEPENDS+=	p5-Attribute-Handlers>=0.77:${PORTSDIR}/devel/p5-Attribute-Handlers
.if ${PERL_LEVEL} < 500701
RUN_DEPENDS+=	p5-Class-ISA>=0.32:${PORTSDIR}/devel/p5-Class-ISA
.if ${PERL_LEVEL} < 500700
RUN_DEPENDS+=	p5-Storable>=2.04:${PORTSDIR}/devel/p5-Storable
.endif
.endif
.endif

.include <bsd.port.post.mk>
