# Created by: Vladimir Timofeev <vovkasm@gmail.com>
# $FreeBSD$

PORTNAME=	DBIx-Class-FrozenColumns
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Store virtual columns inside another column

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-DBIx-Class>=0.07003:databases/p5-DBIx-Class \
		p5-JSON-XS>=0:converters/p5-JSON-XS
BUILD_DEPENDS:=	${RUN_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
