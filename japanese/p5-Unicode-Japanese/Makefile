# New ports collection makefile for:	Unicode::Japanese
# Date created:		25 August 2006
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Unicode-Japanese
PORTVERSION=	0.47
CATEGORIES=	japanese converters perl5
MASTER_SITES=	CPAN

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Perl5 module to handle Japanese character encodings

PERL_CONFIGURE=	5.8.0+
MAN1=		ujconv.1 ujguess.1
MAN3=		Unicode::Japanese.3 Unicode::Japanese::JA.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:NCCFLAGS=*}
