# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org
# $FreeBSD$

PORTNAME=	Class-DBI-Sweet
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extra sweet features for Class::DBI

BUILD_DEPENDS=	p5-Class-DBI>=3.0.12:databases/p5-Class-DBI \
		p5-DBI>=0:databases/p5-DBI \
		p5-Data-Page>=0:databases/p5-Data-Page \
		p5-SQL-Abstract>=1.55:databases/p5-SQL-Abstract
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

post-patch:
	@${REINPLACE_CMD} -e '/DBD::SQLite/d' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
