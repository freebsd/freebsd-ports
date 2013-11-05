# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sub-Exporter-ForMethods
PORTVERSION=	0.100051
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helper routines for using Sub::Exporter to build methods

RUN_DEPENDS=	p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Sub-Exporter>=0.978:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
