# Created by: Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
# $FreeBSD$

PORTNAME=	DBIx-SQLEngine
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extends DBI with high-level operations

BUILD_DEPENDS=	p5-Class-MakeMethods>=0:devel/p5-Class-MakeMethods \
		p5-Class-MixinFactory>=0:devel/p5-Class-MixinFactory \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBIx-AnyDBD>=0:databases/p5-DBIx-AnyDBD
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
