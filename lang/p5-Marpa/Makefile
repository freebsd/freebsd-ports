# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Marpa
PORTVERSION=	0.208
CATEGORIES=	lang textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}000

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse any Language You Can Describe in BNF

BUILD_DEPENDS=	p5-HTML-Parser>=3.64:${PORTSDIR}/www/p5-HTML-Parser \
		p5-PPI>=1.206:${PORTSDIR}/textproc/p5-PPI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
