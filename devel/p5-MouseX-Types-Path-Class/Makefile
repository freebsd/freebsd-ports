# New ports collection makefile for:	p5-MouseX-Types-Path-Class
# Date created:		2009-04-22
# Whom:			TERAMOTO Masahiro <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	MouseX-Types-Path-Class
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MA/MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	A Path::Class type library for Mouse

BUILD_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-Mouse>=0.19:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-Types>=0.01:${PORTSDIR}/devel/p5-MouseX-Types \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-MouseX-Getopt>=0:${PORTSDIR}/devel/p5-MouseX-Getopt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MouseX::Types::Path::Class.3

.include <bsd.port.mk>
