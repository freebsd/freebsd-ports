# New ports collection makefile for:	p5-Devel-DProf
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DProf
PORTVERSION=	19990108
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-Devel-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl code profiler

PERL_CONFIGURE=	yes

MAN1PREFIX=	${PREFIX}
MAN1=		dprofpp.1
MAN3=		Devel::DProf.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500600
IGNORE=		"Version included in perl distribution is newer"
.endif

.include <bsd.port.post.mk>
