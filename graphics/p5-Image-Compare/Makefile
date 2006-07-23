# New ports collection makefile for:	p5-Image-Compare
# Date created:		2006-07-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Compare
PORTVERSION=	0.2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Compare two images in a variety of ways

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common

PERL_CONFIGURE=	yes

MAN3=		Image::Compare.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from graphics/p5-Imager
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
