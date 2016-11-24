# Created by: Brad Davis <brd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JIRA-REST
PORTVERSION=	0.014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extended interface to JIRA REST API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Config-Identity>=0.0019:devel/p5-Config-Identity \
		p5-HTML-TreeBuilder-LibXML>=0:www/p5-HTML-TreeBuilder-LibXML \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON>=0:converters/p5-JSON \
		p5-REST-Client>=0:www/p5-REST-Client \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PLIST_FILES=	%%SITE_PERL%%/JIRA/README.pod \
		%%SITE_PERL%%/JIRA/REST.pm \
		%%PERL5_MAN3%%/JIRA::REST.3.gz

.include <bsd.port.mk>
