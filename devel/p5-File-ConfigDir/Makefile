# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-ConfigDir
PORTVERSION=	0.017
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get directories of configuration files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-HomeDir>=0.50:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
