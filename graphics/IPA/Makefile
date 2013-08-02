# ex:ts=8
# Ports collection makefile for:	ipa
# Created by: ijliao
# $FreeBSD$

PORTNAME=	IPA
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.prima.eu.org/IPA/ CPAN/Prima/KARASIK

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Image Processing Algorithms

RUN_DEPENDS=	p5-Prima>1.24:${PORTSDIR}/x11-toolkits/p5-Prima
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install
MAKE_JOBS_UNSAFE=	yes

MAN1=		iterm.1
MAN3=		IPA.3 IPA::Geometry.3 IPA::Global.3 IPA::Local.3 IPA::Misc.3 \
		IPA::Morphology.3 IPA::Point.3 IPA::Region.3

.include <bsd.port.mk>
