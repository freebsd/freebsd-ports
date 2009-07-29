# New ports collection makefile for:	p5-Filter-Template
# Date created:				15 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filter-Template
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A source filter for inline code templates (macros)

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Filter::Template.3 Filter::Template::UseBytes.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
