# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-TimeStamp
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	DBIx::Class extension to handle date and time based fields

RUN_DEPENDS=	p5-DBIx-Class-DynamicDefault>=0.03:${PORTSDIR}/databases/p5-DBIx-Class-DynamicDefault \
		p5-DBIx-Class>=0.08009:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DateTime>=0.55:${PORTSDIR}/devel/p5-DateTime \
		p5-Time-Warp>=0:${PORTSDIR}/devel/p5-Time-Warp \
		p5-DateTime-Format-MySQL>=0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-SQLite>=0:${PORTSDIR}/devel/p5-DateTime-Format-SQLite
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::TimeStamp.3

post-patch:
	@${REINPLACE_CMD} -i '' '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
