# New ports collection makefile for:	p5-MouseX-ConfigFromFile
# Date created:		2009-04-22
# Whom:			TERAMOTO Masahiro <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	MouseX-ConfigFromFile
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MA/MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	An abstract Mouse role for setting attributes from a configfile

BUILD_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-Mouse>=0.19:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-Types-Path-Class>=0.05:${PORTSDIR}/devel/p5-MouseX-Types-Path-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MouseX::ConfigFromFile.3

.include <bsd.port.mk>
