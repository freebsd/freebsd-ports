# Created by: ijliao
# $FreeBSD$

PORTNAME=	Term-ReadLine-Zoid
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN \
		http://zoidberg.student.utwente.nl/downloads/Term-ReadLine-Zoid/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides an interactive input buffer written in plain PERL

BUILD_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
