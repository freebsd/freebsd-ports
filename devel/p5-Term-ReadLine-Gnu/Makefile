# Ports collection makefile for:	Term::ReadLine::Gnu
# Date created:				Feb 22, 2005
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	Term-ReadLine-Gnu
PORTVERSION=	1.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the GNU Readline/History Library

PERL_CONFIGURE=	yes

MAN3=	Term::ReadLine::Gnu.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		"Need at least perl 5.8 to build"
.endif

.include <bsd.port.post.mk>
