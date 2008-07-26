# New ports collection makefile for:	POE-Component-RSSAggregator
# Date created:		                Aug 1, 2006
# Whom:			                Cheng-Lung Sung
#
# $FreeBSD$
#

PORTNAME=	POE-Component-RSSAggregator
PORTVERSION=	1.11
CATEGORIES=	devel perl5 textproc
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Watch Muliple RSS Feeds for New Headlines

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/RSS/Feed.pm:${PORTSDIR}/textproc/p5-XML-RSS-Feed \
    		p5-POE-Component-Client-DNS>=0.98:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
    		p5-POE-Component-Client-HTTP>=0.51:${PORTSDIR}/www/p5-POE-Component-Client-HTTP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::RSSAggregator.3

.include <bsd.port.mk>
