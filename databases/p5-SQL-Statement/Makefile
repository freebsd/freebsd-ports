# Created by: wolman@cs.washington.edu
# $FreeBSD$

PORTNAME=	SQL-Statement
PORTVERSION=	1.405
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl5 module for SQL parsing and processing

RUN_DEPENDS=	p5-Clone>=0.30:${PORTSDIR}/devel/p5-Clone \
		p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
