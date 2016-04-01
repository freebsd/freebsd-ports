# Created by: Vladimir Timofeev <vovkasm@gmail.com>
# $FreeBSD$

PORTNAME=	HTML-FormHandler-Model-DBIC
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	databases perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Model class for FormHandler unsing DBIx::Class

BUILD_DEPENDS=	p5-DBIx-Class>0:databases/p5-DBIx-Class \
		p5-DBIx-Class-ResultSet-RecursiveUpdate>=0.21:databases/p5-DBIx-Class-ResultSet-RecursiveUpdate \
		p5-HTML-FormHandler>=0.34001:www/p5-HTML-FormHandler \
		p5-Moose>=2.0007:devel/p5-Moose \
		p5-namespace-autoclean>=0.09:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DateTime-Format-MySQL>0:devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-SQLite>0:devel/p5-DateTime-Format-SQLite \
		p5-DateTime-Format-W3CDTF>0:devel/p5-DateTime-Format-W3CDTF

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
