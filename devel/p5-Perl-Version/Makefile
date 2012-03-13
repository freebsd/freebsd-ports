# New ports collection makefile for:	devel/p5-Perl-Version
# Date created:				10 April 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl-Version
PORTVERSION=	1.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse and manipulate Perl version strings

RUN_DEPENDS=	p5-File-Slurp>=9999.12:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		perl-reversion.1
MAN3=		Perl::Version.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 5.008007
RUN_DEPENDS+=	p5-Pod-Parser>=1.3:${PORTSDIR}/textproc/p5-Pod-Parser
BUILD_DEPENDS+=	p5-Pod-Parser>=1.3:${PORTSDIR}/textproc/p5-Pod-Parser
.endif

.include <bsd.port.post.mk>
