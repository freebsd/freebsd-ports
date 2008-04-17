# New ports collection makefile for:	devel/p5-Sort-Key-DateTime
# Date created:				14 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sort-Key-DateTime
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for sorting objects by some DateTime key

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/${PERL_ARCH}/Sort/Key.pm:${PORTSDIR}/devel/p5-Sort-Key
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Sort::Key::DateTime.3

.include <bsd.port.mk>
