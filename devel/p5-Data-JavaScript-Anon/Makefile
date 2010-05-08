# Ports collection makefile for:	devel-p5-Data-JavaScript-Anon
# Date created:				03 April 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	Data-JavaScript-Anon
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Dump big dumb Perl structs to anonymous JavaScript structs

RUN_DEPENDS=	p5-Class-Default>=1.51:${PORTSDIR}/devel/p5-Class-Default \
		p5-Params-Util>=0.01:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=	Data::JavaScript::Anon.3

.include <bsd.port.mk>
