# New ports collection Makefile for:	p5-File-Util
# Date created:				25th April 2007
# Whom: 				jeffhung
#
# $FreeBSD$
#

PORTNAME=	File-Util
PORTVERSION=	3.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeffhung@mail2000.com.tw
COMMENT=	Perl5 module for easy, versatile, portable file handling

RUN_DEPENDS=	p5-Class-OOorNO>=0.01:${PORTSDIR}/devel/p5-Class-OOorNO \
		p5-Exception-Handler>=1:${PORTSDIR}/devel/p5-Exception-Handler
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		File::Util.3

.include <bsd.port.mk>
