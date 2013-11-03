# Created by: Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
# $FreeBSD$

PORTNAME=	DBIx-SQLEngine
PORTVERSION=	0.93
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extends DBI with high-level operations

BUILD_DEPENDS=	p5-DBIx-AnyDBD>=0:${PORTSDIR}/databases/p5-DBIx-AnyDBD \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		p5-Class-MixinFactory>=0:${PORTSDIR}/devel/p5-Class-MixinFactory
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
