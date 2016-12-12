# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JIRA-Client
PORTVERSION=	0.45
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extended interface to JIRA's SOAP API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Data-Util>=0:devel/p5-Data-Util \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}

DEPRECATED=	Deprecated by upstream due to deprecated JIRA's SOAP API
EXPIRATION_DATE=2017-01-31

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
