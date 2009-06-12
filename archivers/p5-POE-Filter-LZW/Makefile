# New ports collection makefile for:	p5-POE-Filter-LZW
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-LZW
PORTVERSION=	1.7.2
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE filter wrapped around Compress::LZW

RUN_DEPENDS=	p5-Compress-LZW>=0:${PORTSDIR}/archivers/p5-Compress-LZW \
		p5-POE>=0.38:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::LZW.3

.include <bsd.port.mk>
