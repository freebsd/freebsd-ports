# Created by: wolman@cs.washington.edu
# $FreeBSD$

PORTNAME=	SQL-Statement
PORTVERSION=	1.410
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for SQL parsing and processing

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Clone>=0.30:devel/p5-Clone \
		p5-Params-Util>=1.00:devel/p5-Params-Util
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
