# ex:ts=8
# Ports collection makefile for:	Regexp::Bind
# Date created:			Jun 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Regexp-Bind
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Regexp
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Bind variables to captured buffers

PERL_CONFIGURE=	yes

MAN3=	Regexp::Bind.3

.include <bsd.port.pre.mk>

# can't pass 'make test'
.if ${PERL_LEVEL} < 500600
IGNORE=		needs perl 5.6.0 or higher, install lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
