# New ports collection makefile for:	p5-DateTime-Format-Oracle
# Date created:		2011-10-19
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Oracle
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse and format Oracle dates and timestamps

BUILD_DEPENDS=	p5-Convert-NLS_DATE_FORMAT>=0.03:${PORTSDIR}/converters/p5-Convert-NLS_DATE_FORMAT \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0:${PORTSDIR}/devel/p5-DateTime-Format-Builder
RUN_DEPENDS=	p5-Convert-NLS_DATE_FORMAT>=0.03:${PORTSDIR}/converters/p5-Convert-NLS_DATE_FORMAT \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0:${PORTSDIR}/devel/p5-DateTime-Format-Builder

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::Oracle.3

.include <bsd.port.mk>
