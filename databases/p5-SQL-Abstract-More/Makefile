# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	SQL-Abstract-More
PORTVERSION=	1.15
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Extension of SQL::Abstract with more constructs and more flexible API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Scalar-Does>0:${PORTSDIR}/devel/p5-Scalar-Does \
		p5-SQL-Abstract>=1.73:${PORTSDIR}/databases/p5-SQL-Abstract
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		SQL::Abstract::More.3

.include <bsd.port.mk>
