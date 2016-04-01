# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	DBD-Multi
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Manage Multiple Data Sources with Failover and Load Balancing

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.19:devel/p5-Class-Accessor \
		p5-DBI>=0:databases/p5-DBI \
		p5-Sys-SigAction>=0.10:devel/p5-Sys-SigAction
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-DBD-SQLite>=1.09:databases/p5-DBD-SQLite \
		p5-Pod-Simple>=0:textproc/p5-Pod-Simple \
		p5-Test-Exception>=0.21:devel/p5-Test-Exception \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
