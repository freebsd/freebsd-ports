# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooX-ConfigFromFile
PORTVERSION=	0.009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moo eXtension for initializing objects from config file

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Any>=0:devel/p5-Config-Any \
		p5-File-Find-Rule>=0.30:devel/p5-File-Find-Rule \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-Moo>=1.003000:devel/p5-Moo \
		p5-MooX-File-ConfigDir>=0.002:devel/p5-MooX-File-ConfigDir
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
