# New ports collection makefile for:	Regexp::Assemble::Compressed
# Date created:		27 Dec 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Regexp-Assemble-Compressed
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to compress Regular Expression

RUN_DEPENDS=	\
	p5-Regexp-Assemble>0:${PORTSDIR}/devel/p5-Regexp-Assemble
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Regexp::Assemble::Compressed.3

.include <bsd.port.mk>
