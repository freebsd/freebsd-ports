# New ports collection makefile for:	p5-Image-Imgur
# Date created:		2010-10-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Imgur
PORTVERSION=	0.01
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for uploading images to http://imgur.com

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Image::Imgur.3

.include <bsd.port.mk>
