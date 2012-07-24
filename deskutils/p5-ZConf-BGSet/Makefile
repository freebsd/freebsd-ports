# New ports collection makefile for:	p5-ZConf-BGSet
# Date created:		2008-02-08
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-BGSet
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Background management utility and Perl module that uses ZConf

BUILD_DEPENDS=	p5-Image-Size-FillFullSelect>=0.1.0:${PORTSDIR}/graphics/p5-Image-Size-FillFullSelect \
		p5-ZConf>=:${PORTSDIR}/net/p5-ZConf \
		${LOCALBASE}/bin/hsetroot:${PORTSDIR}/graphics/hsetroot \
		p5-Imager-AverageGray>=0.0.0:${PORTSDIR}/graphics/p5-Imager-AverageGray \
		p5-X11-Resolution>=0.0.0:${PORTSDIR}/x11/p5-X11-Resolution \
		p5-String-ShellQuote>=1.04:${PORTSDIR}/textproc/p5-String-ShellQuote
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ZConf::BGSet.3

.include <bsd.port.mk>
