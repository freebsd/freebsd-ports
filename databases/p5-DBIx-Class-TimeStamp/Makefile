# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-TimeStamp
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	DBIx::Class extension to handle date and time based fields

RUN_DEPENDS=	p5-DBIx-Class-DynamicDefault>=0.03:databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:databases/p5-DBIx-Class \
		p5-DateTime>=0.55:devel/p5-DateTime \
		p5-Time-Warp>=0:devel/p5-Time-Warp \
		p5-DateTime-Format-MySQL>=0:devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-SQLite>=0:devel/p5-DateTime-Format-SQLite
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
