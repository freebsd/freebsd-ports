# New ports collection makefile for:   Config-Properties
# Date created:           28 December 2006
# Whom:                   Craig Manley
#
# $FreeBSD$
#

PORTNAME=	Config-Properties
PORTVERSION=	0.65
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	cmanley@xs4all.nl
COMMENT=	Read and write property files

PERL_CONFIGURE=	yes

MAN3=	Config::Properties.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
