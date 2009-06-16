# Ports collection makefile for:	Sane
# Date created:				2009/01/12
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Sane
PORTVERSION=	0.03
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/R/RA/RATCLIFFE
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Perl extension for the SANE (Scanner Access Now Easy) Project

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
  		p5-ExtUtils-PkgConfig>=1.03:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		sane-config:${PORTSDIR}/graphics/sane-backends

PERL_CONFIGURE=	YES

MAN3=		Sane.3 \

.include <bsd.port.mk>
