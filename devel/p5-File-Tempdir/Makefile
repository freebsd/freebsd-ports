# New ports collection makefile for:	p5-File-Tempdir
# Date created:		2007-01-02
# Whom:	      		loader <loader@freebsdmall.com>
#
# $FreeBSD$
#

PORTNAME=	File-Tempdir
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	loader@freebsdmall.com
COMMENT=	Perl5 module to provide an object interface for File::Temp

PERL_CONFIGURE=	yes

MAN3=		File::Tempdir.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
