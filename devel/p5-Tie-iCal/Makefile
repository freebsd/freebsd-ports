# New ports collection makefile for:	p5-Tie-iCal
# Date created:				13 June 2005
# Whom:	      				TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-iCal
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Tie iCal files to Perl hashes

PERL_CONFIGURE=	yes

MAN3=		Tie::iCal.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BROKEN=		"Requires newer version of Perl with Tie::File 0.97 or later"
.endif

.include <bsd.port.post.mk>
