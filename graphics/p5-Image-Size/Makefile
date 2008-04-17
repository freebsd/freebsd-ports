# New ports collection makefile for:	p5-Image-Size
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Size
PORTVERSION=	3.01
CATEGORIES=	graphics www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tolid@plab.ku.dk
COMMENT=	Perl5 module to determine the size of images in several common formats

BUILD_DEPENDS=	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		imgsize.1
MAN3=		Image::Size.3

.include <bsd.port.mk>
