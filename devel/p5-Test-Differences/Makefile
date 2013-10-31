# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Differences
PORTVERSION=	0.610
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Differences - Test strings and data structures for differences

BUILD_DEPENDS=	p5-Text-Diff>=0.35:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS=	p5-Text-Diff>=0.35:${PORTSDIR}/textproc/p5-Text-Diff

PORTSCOUT=	skipv:0.4801

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
RUN_DEPENDS+=	p5-Data-Dumper>=2.126:${PORTSDIR}/devel/p5-Data-Dumper
.endif

.include <bsd.port.post.mk>
