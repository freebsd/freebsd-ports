# ex:ts=8
# Ports collection makefile for:	ipa
# Date created:			Aug 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	IPA
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.prima.eu.org/IPA/ CPAN/Prima/KARASIK

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Image Processing Algorithms

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Prima.pm:${PORTSDIR}/x11-toolkits/p5-Prima
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN1=		iterm.1
MAN3=		IPA.3 IPA::Geometry.3 IPA::Global.3 IPA::Local.3 IPA::Misc.3 \
		IPA::Morphology.3 IPA::Point.3 IPA::Region.3

.include <bsd.port.mk>
