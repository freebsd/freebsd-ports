# New ports collection makefile for:	p5-Image-Imlib2
# Date created:				September 11th, 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Imlib2
PORTVERSION=	1.01
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to the Imlib2 image library

LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2

PERL_MODBUILD=	yes

MAN3=		Image::Imlib2.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
