# New ports collection makefile for:	p5-Filesys-Virtual
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Virtual
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension to provide a framework for a virtual filesystem

PERL_CONFIGURE=	yes

MAN3=		Filesys::Virtual.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
post-patch:
	@${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Virtual.pm
.endif

.include <bsd.port.post.mk>
