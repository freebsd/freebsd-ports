# Created by: Cheng-Lung Sung
# $FreeBSD$

PORTNAME=	POE-Component-RSSAggregator
PORTVERSION=	1.11
CATEGORIES=	devel perl5 textproc
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Watch Muliple RSS Feeds for New Headlines

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-RSS-Feed>=0:${PORTSDIR}/textproc/p5-XML-RSS-Feed \
    		p5-POE-Component-Client-DNS>=0.98:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
    		p5-POE-Component-Client-HTTP>=0.51:${PORTSDIR}/www/p5-POE-Component-Client-HTTP
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
