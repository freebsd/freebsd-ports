# New ports collection makefile for:	p5-Apache-Filter
# Date created:				September 11th, 2003
# Whom:	      				Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Imlib2
PORTVERSION=	0.12
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to the Imlib2 image library

LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2

PERL_CONFIGURE=	yes

MAN3=		Image::Imlib2.3

.include "../../devel/p5-Module-Build/inc.build.mk"
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		'Does not compile'
.endif

.include <bsd.port.post.mk>
