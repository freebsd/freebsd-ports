# ex:ts=8
# Ports collection makefile for:	VCS::Lite
# Date created:			Jan 2, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	VCS-Lite
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Minimal version control system

BUILD_DEPENDS=	p5-Algorithm-Diff>=1.13:${PORTSDIR}/devel/p5-Algorithm-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	VCS::Lite.3 VCS::Lite::Delta.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl5.6. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
