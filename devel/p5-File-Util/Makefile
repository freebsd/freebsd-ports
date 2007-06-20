# New ports collection Makefile for:	p5-File-Util
# Date created:				25th April 2007
# Whom: 				jeffhung
#
# $FreeBSD$
#

PORTNAME=	File-Util
PORTVERSION=	3.22
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jeffhung@mail2000.com.tw
COMMENT=	Perl5 module for easy, versatile, portable file handling

RUN_DEPENDS=	${SITE_PERL}/Class/OOorNO.pm:${PORTSDIR}/devel/p5-Class-OOorNO \
		${SITE_PERL}/Exception/Handler.pm:${PORTSDIR}/devel/p5-Exception-Handler
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		File::Util.3

.include <bsd.port.mk>
