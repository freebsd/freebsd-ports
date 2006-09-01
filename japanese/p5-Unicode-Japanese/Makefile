# New ports collection makefile for:	Unicode::Japanese
# Date created:		25 August 2006
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Unicode-Japanese
PORTVERSION=	0.37
CATEGORIES=	japanese converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/H/HI/HIO

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Perl5 module to handle Japanese character encodings

PERL_CONFIGURE=	yes
MAN1=		ujconv.1
MAN3=		Unicode::Japanese.3 Unicode::Japanese::JA.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.if ${PERL_LEVEL} < 500800
IGNORE=		needs perl 5.8.0 or higher, install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
