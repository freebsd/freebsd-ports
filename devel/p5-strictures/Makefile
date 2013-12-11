# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strictures
PORTVERSION=	1.005002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Turn on strict and make all warnings fatal

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-bareword-filehandles>=0:${PORTSDIR}/devel/p5-bareword-filehandles \
		p5-indirect>=0:${PORTSDIR}/devel/p5-indirect \
		p5-multidimensional>=0:${PORTSDIR}/devel/p5-multidimensional
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
