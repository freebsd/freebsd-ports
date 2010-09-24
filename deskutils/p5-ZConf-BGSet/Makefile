# New ports collection makefile for:	p5-ZConf-BGSet
# Date created:		2008-02-08
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-BGSet
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Background management utitility and Perl module that uses ZConf

RUN_DEPENDS=	${SITE_PERL}/Image/Size/FillFullSelect.pm:${PORTSDIR}/graphics/p5-Image-Size-FillFullSelect \
		${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		${LOCALBASE}/bin/hsetroot:${PORTSDIR}/graphics/hsetroot \
		${SITE_PERL}/Imager/AverageGray.pm:${PORTSDIR}/graphics/p5-Imager-AverageGray \
		${SITE_PERL}/X11/Resolution.pm:${PORTSDIR}/x11/p5-X11-Resolution \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote

PERL_CONFIGURE=	yes

MAN3=		ZConf::BGSet.3

.include <bsd.port.mk>
