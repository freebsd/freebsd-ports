# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Metabase-Fact
PORTVERSION=	0.025
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Metabase Facts

BUILD_DEPENDS=	p5-JSON>=2.0:converters/p5-JSON \
		p5-Data-GUID>=0:devel/p5-Data-GUID \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-CPAN-DistnameInfo>0:devel/p5-CPAN-DistnameInfo
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
