# New ports collection makefile for:	astro/p5-Astro-Sunrise
# Date created:				25 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Astro-Sunrise
PORTVERSION=	0.91
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl extension for computing the sunrise/sunset on a given day

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime

PERL_CONFIGURE=	yes

MAN3=		Astro::Sunrise.3

post-patch:
	${PERL} -pi -e 's/(qw\(.*)\[1\];/($$1)[1];/; s/\r\n/\n/;' \
		${WRKSRC}/Sunrise.pm

.include <bsd.port.mk>
