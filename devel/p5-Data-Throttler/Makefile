# New ports collection makefile for:	p5-Data-Throttler
# Date created:		2008-01-30
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Data-Throttler
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Limit data throughput

BUILD_DEPENDS=	p5-DBM-Deep>=1.0001:${PORTSDIR}/databases/p5-DBM-Deep \
		p5-Log-Log4perl>=1:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Set-IntSpan>=0:${PORTSDIR}/math/p5-Set-IntSpan \
		p5-Text-ASCIITable>=0:${PORTSDIR}/textproc/p5-Text-ASCIITable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::Throttler.3

.include <bsd.port.mk>
