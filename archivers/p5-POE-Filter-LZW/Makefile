# New ports collection makefile for:	p5-POE-Filter-LZW
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-LZW
PORTVERSION=	1.2
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A POE filter wrapped around Compress::LZW

RUN_DEPENDS=	${SITE_PERL}/Compress/LZW.pm:${PORTSDIR}/archivers/p5-Compress-LZW \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::LZW.3

.include <bsd.port.mk>
