# New ports collection makefile for:	p5-Devel-Peek
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-Peek
PORTVERSION=	0.96
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl5 data debugging tool for the XS programmer

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500600
IGNORE=		"Version included in perl distribution is newer"
.endif

MAN3=		Devel::Peek.3

.include <bsd.port.post.mk>
