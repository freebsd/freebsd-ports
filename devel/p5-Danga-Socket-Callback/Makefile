# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Danga-Socket-Callback
PORTVERSION=	0.013
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Danga
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Use Danga::Socket From Callbacks

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Danga-Socket>=0:${PORTSDIR}/devel/p5-Danga-Socket
RUN_DEPENDS=	p5-Danga-Socket>=0:${PORTSDIR}/devel/p5-Danga-Socket

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Danga::Socket::Callback.3

.include <bsd.port.mk>
