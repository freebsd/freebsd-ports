# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Schema-PopulateMore
PORTVERSION=	0.17
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Enhanced populate method

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Visitor>=0.27:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-DateTimeX-Easy>=0.089:${PORTSDIR}/devel/p5-DateTimeX-Easy \
		p5-List-MoreUtils>=0.30:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=1.24:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08127:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DateTime-Format-SQLite>=0.11:${PORTSDIR}/devel/p5-DateTime-Format-SQLite \
		p5-Path-Class>=0.23:${PORTSDIR}/devel/p5-Path-Class \
		p5-SQL-Translator>0.11007:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-YAML-Tiny>=1.38:${PORTSDIR}/textproc/p5-YAML-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
