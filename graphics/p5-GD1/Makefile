# New ports collection makefile for:    p5-GD
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GD
PORTVERSION=	1.41
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A perl5 interface to Gd Graphics Library

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		GD.3

.include <bsd.port.mk>
