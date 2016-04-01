# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Rose-DB
PORTVERSION=	0.777
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI wrapper and abstraction layer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Bit-Vector>=6.4:math/p5-Bit-Vector \
		p5-Clone-PP>=0:devel/p5-Clone-PP \
		p5-DBI>=0:databases/p5-DBI \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-MySQL>=0:devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-Oracle>=0:devel/p5-DateTime-Format-Oracle \
		p5-DateTime-Format-Pg>=0.11:devel/p5-DateTime-Format-Pg \
		p5-Rose-DateTime>=0.532,1:devel/p5-Rose-DateTime \
		p5-Rose-Object>=0.854:devel/p5-Rose-Object \
		p5-SQL-ReservedWords>=0:databases/p5-SQL-ReservedWords \
		p5-Time-Clock>=0:devel/p5-Time-Clock \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.7591

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
