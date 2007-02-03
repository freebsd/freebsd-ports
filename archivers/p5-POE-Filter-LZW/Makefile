# New ports collection makefile for:	p5-POE-Filter-LZW
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-LZW
PORTVERSION=	1.6.0
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE filter wrapped around Compress::LZW

RUN_DEPENDS=	${SITE_PERL}/Compress/LZW.pm:${PORTSDIR}/archivers/p5-Compress-LZW \
		p5-POE>=0.38:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::LZW.3

.include <bsd.port.mk>
