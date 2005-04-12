# New ports collection makefile for:	p5-File-Type
# Date created:		Fri Feb 20 20:02:30 EST 2004
# Whom:	      		Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	File-Type
PORTVERSION=	0.22
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Determine file type using magic

PERL_CONFIGURE=	YES

MAN3=	File::Type.3 \
	File::Type::Builder.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
