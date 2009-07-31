# New ports collection makefile for:	p5-Image-Compare
# Date created:		2006-07-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Compare
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Compare two images in a variety of ways

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Image::Compare.3 \
		Image::Compare::AVG_THRESHOLD.3 \
		Image::Compare::Comparator.3 \
		Image::Compare::EXACT.3 \
		Image::Compare::IMAGE.3 \
		Image::Compare::THRESHOLD.3 \
		Image::Compare::THRESHOLD_COUNT.3

.include <bsd.port.mk>
