# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DateTime-Format-Oracle
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse and format Oracle dates and timestamps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Convert-NLS_DATE_FORMAT>=0.03:converters/p5-Convert-NLS_DATE_FORMAT \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0:devel/p5-DateTime-Format-Builder
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
