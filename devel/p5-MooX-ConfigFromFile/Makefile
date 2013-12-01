# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooX-ConfigFromFile
PORTVERSION=	0.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moo eXtension for initializing objects from config file

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moo>=1.003000:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-File-ConfigDir>=0.002:${PORTSDIR}/devel/p5-MooX-File-ConfigDir
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
