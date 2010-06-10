# New ports collection makefile for:	p5-File-MMagic-XS
# Date created:				18 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-MMagic-XS
PORTVERSION=	0.09006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Guess File Type With XS (a la mod_mime_magic)

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
  p5-ExtUtils-ParseXS>=2.21:${PORTSDIR}/devel/p5-ExtUtils-ParseXS

MAKE_JOBS_UNSAFE=	yes

MAN3=	File::MMagic::XS.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
