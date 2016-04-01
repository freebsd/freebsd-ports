# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Schema-PopulateMore
PORTVERSION=	0.19
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Enhanced populate method

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Visitor>=0.27:devel/p5-Data-Visitor \
		p5-DateTimeX-Easy>=0.089:devel/p5-DateTimeX-Easy \
		p5-List-MoreUtils>=0.30:lang/p5-List-MoreUtils \
		p5-Moo>=1.004006:devel/p5-Moo \
		p5-MooX-HandlesVia>=0.001005:devel/p5-MooX-HandlesVia \
		p5-Type-Tiny>=0.042:devel/p5-Type-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08127:databases/p5-DBIx-Class \
		p5-DateTime-Format-SQLite>=0.11:devel/p5-DateTime-Format-SQLite \
		p5-Path-Class>=0.23:devel/p5-Path-Class \
		p5-SQL-Translator>0.11020:databases/p5-SQL-Translator \
		p5-YAML-Tiny>=1.48:textproc/p5-YAML-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
