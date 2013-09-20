# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Starlink-AST
PORTVERSION=	1.02
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TJENNESS
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Interface to the Starlink AST library

BUILD_DEPENDS=	p5-Test-Number-Delta>=0:${PORTSDIR}/devel/p5-Test-Number-Delta
RUN_DEPENDS=	p5-Test-Number-Delta>=0:${PORTSDIR}/devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	modbuild
NO_STAGE=	yes

MAN3=		Starlink::AST.3 \
		Starlink::AST::PGPLOT.3 \
		Starlink::AST::Tk.3 \
		Starlink::AST::PLplot.3

.include <bsd.port.mk>
