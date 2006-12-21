# New ports collection makefile for:	p5-Term-Animation
# Date created:				Sep 16, 2005
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Term-Animation
PORTVERSION=	2.4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	ASCII sprite animation framework

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Term::Animation.3 Term::Animation::Entity.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6+, install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
