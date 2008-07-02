# New ports collection makefile for:	p5-POE-Filter-Bzip2
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-Bzip2
PORTVERSION=	1.5.8
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE filter wrapped around Compress::Bzip2

RUN_DEPENDS=	p5-Compress-Bzip2>=2.08:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		p5-POE>=0.38:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::Bzip2.3

.include <bsd.port.mk>
