# New ports collection makefile for:	Data::MessagePack
# Date created:		22 Dec 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-MessagePack
PORTVERSION=	0.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for MessagePack

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--xs

MAKE_JOBS_UNSAFE=	yes

MAN3=	Data::MessagePack.3 \
	Data::MessagePack::PP.3 \
	Data::MessagePack::Unpacker.3

.include <bsd.port.mk>
